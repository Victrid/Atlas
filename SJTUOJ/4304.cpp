#include <cstdio>
#include <iostream>
using namespace std;
//??pa3mep??
long long mushroom[400010]={0};
struct set {
    //segment tree
    int sleft;
    int sright;
    int current;
    long long& value;
    set left() {
        return set{sleft, (sleft + sright) >> 1, current << 1, mushroom[current << 1]};
    }
    set right() {
        return set{((sleft + sright) >> 1) + 1, sright, current << 1 | 1, mushroom[current << 1 | 1]};
    }
    bool isleaf() { return !(sright - sleft); }
    void update_fathers() {
        int z = current >> 1;
        while (z != 0) {
            mushroom[z] = mushroom[z << 1] + mushroom[z << 1 | 1];
            z >>= 1;
        }
        return;
    }
};
void buildtree(set root) {
    if (root.isleaf()) {
        scanf("%lld", mushroom + root.current);
        return;
    }
    buildtree(root.left());
    buildtree(root.right());
    root.value = root.left().value + root.right().value;
    return;
}
void single_addition(int count, int add, set s) {
    if (count == s.sleft && count == s.sright) {
        s.value += add;
        s.update_fathers();
        return;
    }
    if (count <= (s.sleft + s.sright) >> 1)
        return single_addition(count, add, s.left());
    else
        return single_addition(count, add, s.right());
}
long long sequence_query(int lbound, int rbound, set s) {
    if (lbound <= s.sleft && rbound >= s.sright)
        return s.value;
    int mid = (s.sleft + s.sright) >> 1;
    long long ans = 0;
    if (lbound <= mid) {
        ans += sequence_query(lbound, rbound, s.left());
    }
    if (rbound >= mid + 1) {
        ans += sequence_query(lbound, rbound, s.right());
    }
    return ans;
}
struct input {
    enum operat { SELL,
                  GET,
                  QUERY } operation;
    int i;
    int j;
};
input getinput() {
    char c;
    input ans;
    do {
        c = getchar();
    } while (c == ' ' || c == '\n');
    switch (c) {
    case 'S':
        ans.operation = input::SELL;
        break;
    case 'G':
        ans.operation = input::GET;
        break;
    case 'Q':
        ans.operation = input::QUERY;
        break;
    }
    do {
        c = getchar();
    } while (c != ' ' && c != '\n');
    scanf("%d %d", &(ans.i), &(ans.j));
    return ans;
}
int main() {
    int P;
    scanf("%d", &P);
    buildtree(set{1, P, 1, mushroom[1]});
    int M;
    scanf("%d", &M);
    while (M--) {
        input ans = getinput();
        switch (ans.operation) {
        case input::SELL:
            single_addition(ans.i, -ans.j, set{1, P, 1, mushroom[1]});
            break;
        case input::QUERY:
            printf("%lld\n", sequence_query(ans.i, ans.j, set{1, P, 1, mushroom[1]}));
            break;
        case input::GET:
            single_addition(ans.i, ans.j, set{1, P, 1, mushroom[1]});
            break;
        }
    }
    return 0;
}