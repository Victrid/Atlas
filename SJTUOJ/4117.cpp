#include <cstdio>
#include <iostream>
using namespace std;
//*shitcode
// I'll rewrite the code.
//The lazy tag is really confusing.
//I may just follow the tutorial.
//400005
long long seq[21];
long long tags[21] = {0};
struct set {
    //segmenttree
    //Tree access helper
    int leftbound;
    int rightbound;
    int current;
    long long& value;
    long long& tag;
    set left() {
        return set{
            leftbound, (leftbound + rightbound) / 2, current << 1, seq[current << 1], tags[current << 1]};
    }
    set right() {
        return set{
            (leftbound + rightbound) / 2 + 1, rightbound, current << 1 | 1, seq[current << 1 | 1], tags[current << 1 | 1]};
    }
    int addtag() {
        return (rightbound - leftbound + 1) * tag;
    }
    bool isleaf() { return !(rightbound - leftbound); }
    int update_fathers() {
        int z = current >> 1;
        while (z != 0) {
            seq[z] = seq[z << 1] + seq[z << 1 | 1];
            z >>= 1;
        }
        return 0;
    }
};
void buildtree(set s) {
    if (s.leftbound == s.rightbound)
        cin >> s.value;
    else {
        buildtree(s.left());
        buildtree(s.right());
        s.value = s.left().value + s.right().value;
    }
}
void buildtree(int total) {
    buildtree(set{1, total, 1, seq[1], tags[1]});
}
int tagproc(set s) {
    if (!s.isleaf()) {
        if (!s.left().isleaf())
            s.left().tag += s.tag;
        s.left().value += s.tag * (s.left().rightbound - s.left().leftbound + 1);
        if (!s.right().isleaf())
            s.right().tag += s.tag;
        s.right().value += s.tag * (s.right().rightbound - s.right().leftbound + 1);
    }
    s.tag = 0;
    return 0;
}
long long getsum(int oper_left, int oper_right, set s) {
    if (oper_left <= s.leftbound && s.rightbound <= oper_right) {
        if (s.tag != 0)
            tagproc(s);
        return s.value;
    } else {
        long long sum = 0;
        int mid       = (s.leftbound + s.rightbound) / 2;
        if (s.tag != 0)
            tagproc(s);
        if (oper_left <= mid)
            sum += getsum(oper_left, oper_right, s.left());
        if (oper_right > mid)
            sum += getsum(oper_left, oper_right, s.right());
        return sum;
    }
}
long long getsum(int oper_left, int oper_right, int total) {
    return getsum(oper_left, oper_right, set{1, total, 1, seq[1], tags[1]});
}
int addsequence(int oper_left, int oper_right, set s, long long add) {
    if (oper_left <= s.leftbound && s.rightbound <= oper_right) {
        s.value += add * (s.rightbound - s.leftbound + 1);
        s.tag += add;
        s.update_fathers();
        return 0;
    } else {
        int mid = (s.leftbound + s.rightbound) / 2;
        if (oper_left <= mid) {
            //Although no tags,
            //father's value add first.
            s.value += add * (mid - oper_left + 1);
            addsequence(oper_left, oper_right, s.left(), add);
        }
        if (oper_right > mid) {
            s.value += add * (oper_right - mid);
            addsequence(oper_left, oper_right, s.right(), add);
        }
        return 0;
    }
}
int addsequence(int oper_left, int oper_right, int total, long long add) {
    return addsequence(oper_left, oper_right, set{1, total, 1, seq[1], tags[1]}, add);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    buildtree(n);
    char op;
    int oper_left, oper_right, oper_add;
    for (int i = 0; i < m; i++) {
        do {
            op = getchar();
        } while (op == ' ' || op == '\n');
        if (op == 'Q') {
            scanf("%d %d", &oper_left, &oper_right);
            printf("%lld\n", getsum(oper_left, oper_right, n));
        } else {
            scanf("%d %d %d", &oper_left, &oper_right, &oper_add);
            addsequence(oper_left, oper_right, n, oper_add);
        }
    }
    return 0;
}