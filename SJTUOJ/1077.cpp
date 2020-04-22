#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long dp[35][35] = {};
int root[35][35]     = {};
long long search(int l, int r) {
    if (l > r)
        return 1;
    if (dp[l][r] != 0)
        return dp[l][r];
    for (int i = l; i <= r; i++) {
        long long pas = search(l, i - 1) * search(i + 1, r) + search(i, i);
        if (pas > dp[l][r]) {
            dp[l][r]   = pas;
            root[l][r] = i;
        }
    }
    return dp[l][r];
}
bool isfirst = false;
void findpath(int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        if (isfirst)
            putchar(' ');
        isfirst = true;
        printf("%d", l);
        return;
    }
    if (isfirst)
        putchar(' ');
    isfirst = true;
    printf("%d", root[l][r]);
    findpath(l, root[l][r] - 1);
    findpath(root[l][r] + 1, r);
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &(dp[i][i]));
    }
    printf("%lld\n", search(1, n));
    findpath(1, n);
    return 0;
}