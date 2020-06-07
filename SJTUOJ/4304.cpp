#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long seq[400005] = {};

long long read() {
    long long x = 0;
    bool w      = 0;
    char ch     = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    return w ? -x : x;
}

struct set {
    int l;
    int r;
    int current;
    long long& value;
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
        s.value = read();
        return;
    }
    buildtree(s.left());
    buildtree(s.right());
    s.value = s.left().value + s.right().value;
    return;
}
long long query(int l, int r, set s) {
    if (l <= s.l && s.r <= r) {
        return s.value;
    }
    int mid      = (s.l + s.r) >> 1;
    long long q1 = 0, q2 = 0;
    if (l <= mid) {
        q1 = query(l, r, s.left());
    }
    if (r > mid) {
        q2 = query(l, r, s.right());
    }
    return q1 + q2;
}
void update(int l, int r, set s) {
    if (l < s.l || s.r < l) {
        return;
    }
    if (s.isleaf()) {
        s.value += r;
        return;
    }
    int mid = (s.l + s.r) >> 1;
    if (l <= mid) {
        update(l, r, s.left());
    } else {
        update(l, r, s.right());
    }
    s.value = s.left().value + s.right().value;
    return;
}
int main() {
    //one group
    int N, M;
    N = read();
    buildtree(set{1, N, 1, seq[1]});
    M = read();
    char a[30];
    int l;
    int r;
    while (M--) {
        scanf("%s", a);
        l = read();
        r = read();
        switch (a[0]) {
        case 'Q':
            printf("%lld\n", query(l, r, set{1, N, 1, seq[1]}));
            break;
        case 'G':
            update(l, r, set{1, N, 1, seq[1]});
            break;
        case 'S':
            update(l, -r, set{1, N, 1, seq[1]});
            break;
        }
    }
    return 0;
}