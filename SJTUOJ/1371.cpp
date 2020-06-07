#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
//??前缀和
int strage[1000000] = {0};
int accu[1000000]   = {0};
int main() {
    int n, m, imax = 0, score;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int score = 0;
        scanf("%d", &score);
        ++strage[score];
        imax = max(score, imax);
    }
    accu[0] = 0;
    for (int i = 1; i <= imax; ++i)
        accu[i] = accu[i - 1] + strage[i];
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if (b > imax)
            b = imax;
        printf("%d\n", accu[b] - accu[a - 1]);
    }
    return 0;
}