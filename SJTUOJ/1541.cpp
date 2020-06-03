#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long nums[200010];
long long st[200010][25];
inline int lg(int n) { return n ? lg(n / 2) + 1 : -1; }
int main() {
    int n, k, lgk;
    scanf("%d%d", &k, &n);
    lgk = lg(k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
        st[i][0] = i;
    }
    for (int j = 1; j <= lgk; j++) {
        for (int i = 1; i <= n; i++) {
            st[i][j] = nums[st[i][j - 1]] > nums[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        }
    }
    for (int i = 1; i <= n - k + 1; i++) {
        if (i - 1)
            printf(" ");
        printf("%lld", max(nums[st[i][lgk]], nums[st[i + k - (1 << lgk)][lgk]]));
    }
    return 0;
}