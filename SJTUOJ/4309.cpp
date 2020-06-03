#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int nums[10005];
int st[10005][15];
inline int lg(int n) { return n ? lg(n / 2) + 1 : -1; }
int main() {
    int n, k, lgn;
    scanf("%d", &n);
    lgn = lg(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        st[i][0] = i;
    }
    for (int j = 1; j <= lgn; j++) {
        for (int i = 1; i <= n; i++) {
            st[i][j] = nums[st[i][j - 1]] > nums[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        }
    }
    int ll, rr;
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &ll, &rr);
        if (ll == rr)
            printf("%d\n", nums[st[ll][0]]);
        else
            printf("%d\n", max(nums[st[ll][lg(rr - ll)]], nums[st[rr + 1 - (1 << lg(rr - ll))][lg(rr - ll)]]));
    }
    return 0;
}