#include <cstdio>
#include <iostream>
using namespace std;
long long strage[400005];
int treesize;
void swap(long long& a1, long long& a2) {
    if (a1 != a2) {
        a1 ^= a2;
        a2 ^= a1;
        a1 ^= a2;
    }
    return;
};
void insert(long long i) {
    strage[++treesize] = i;
    int x              = treesize;
    while (x != 1) {
        if (strage[x] < strage[x >> 1]) {
            swap(strage[x], strage[x >> 1]);
            x >>= 1;
        } else
            break;
    }
    return;
}
long long pop() {
    swap(strage[1], strage[treesize]);
    treesize--;
    int i = 2;
    while (i <= treesize) {
        if ((i | 1) <= treesize && strage[i | 1] < strage[i])
            i |= 1;
        if (strage[i] < strage[i >> 1]) {
            swap(strage[i], strage[i >> 1]);
            i <<= 1;
        } else
            break;
    }
    return strage[treesize + 1];
}
int main() {
    int n, m, a;
    scanf("%d%d", &m, &n);
    int p = m - (m - 2 * n) / (n - 1) * (n - 1);
    while (p > n)
        p -= (n - 1);
    p        = (n - p) % n;
    treesize = 0;
    while (p--) {
        insert(0);
    }
    while (m--) {
        scanf("%d", &a);
        insert(a);
    }
    long long tot = 0, cur;
    while (treesize != 1) {
        cur = 0;
        for (int i = 0; i < n; i++) {
            cur += pop();
        }
        tot += cur;
        insert(cur);
    }
    printf("%lld", tot);
    return 0;
}