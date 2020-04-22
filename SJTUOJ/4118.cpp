#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long dp[30][30][30] = {};
char pre[30];
char pos[30];
int m;
long long C[30][30] = {};
long long c(int h, int l) {
    if (C[h][l] != 0)
        return C[h][l];
    if (h == l || h == 0)
        return 1;
    else
        C[h][l] = c(h, l - 1) + c(h - 1, l - 1);
    return C[h][l];
}
//It's my fault
//! every digit can appear only once.
long long search(int prep, int posp, int length) {
    int total     = 0;
    long long ans = 1;
    for (int i = prep + 1, j = posp; i < prep + length;) {
        int subpre = i, subpos = j;
        while (j < posp + length - 1 && pre[subpre] != pos[j])
            ++i, ++j;
        ++total;
        ans *= search(subpre, subpos, j - subpos + 1);
        ++i, ++j;
    }
    ans *= c(total, m);
    return ans;
}

int main() {
    scanf("%d %s %s", &m, pre, pos);
    cout << search(0, 0, strlen(pre));
    return 0;
}