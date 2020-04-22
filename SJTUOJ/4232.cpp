#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int seq[800005] = {};
struct set {
    int l;
    int r;
    int current;
    int& value;
    set left() {
        return set{l, (l + r) >> 1, current << 1, seq[current << 1]};
    }
    set right() {
        return set{((l + r) >> 1) + 1, r, current << 1 | 1, seq[current << 1 | 1]};
    }
    bool isleaf() { return !(r - l); }
};
void buildtree(set s) {
    if (s.isleaf()) {
        scanf("%d", &(s.value));
        return;
    }
    buildtree(s.left());
    buildtree(s.right());
    s.value = max(s.left().value, s.right().value);
    return;
}
int query(int l, int r, set s) {
    if (l <= s.l && s.r <= r) {
        return s.value;
    }
    int mid = (s.l + s.r) >> 1;
    int q1 = -1000, q2 = -1000;
    if (l <= mid) {
        q1 = query(l, r, s.left());
    }
    if (r > mid) {
        q2 = query(l, r, s.right());
    }
    return max(q1, q2);
}
void update(int l, int r, set s) {
    if (l < s.l || s.r < l) {
        return;
    }
    if (s.isleaf()) {
        s.value = r;
        return;
    }
    int mid = (s.l + s.r) >> 1;
    if (l <= mid) {
        update(l, r, s.left());
    } else {
        update(l, r, s.right());
    }
    s.value = max(s.left().value, s.right().value);
    return;
}
int main() {
    //one group
    int N, M;
    char ch;
    int l, r;
    while (cin >> N >> M) {
        buildtree(set{1, N, 1, seq[1]});
        while (M--) {
            scanf("\n%c %d %d", &ch, &l, &r);
            switch (ch) {
            case 'Q':
                printf("%d\n", query(l, r, set{1, N, 1, seq[1]}));
                break;
            case 'U':
                update(l, r, set{1, N, 1, seq[1]});
            }
        }
    }
    return 0;
}