#include <cmath>
#include <iostream>
using namespace std;
int pic[1005][1005] = {0};
int n, m;
inline int getpixel(int i, int j, int k) {
    return pic[(i * k > n) ? n : i * k][j * k > m ? m : j * k];
}
int getdelta(int i, int j, int k) {
    int ans = getpixel(i, j, k) - getpixel(i - 1, j, k) - getpixel(i, j - 1, k) + getpixel(i - 1, j - 1, k);
    return min(ans, k * k - ans);
}
int gettotals(int k) {
    int nmax   = ceil(n / (double)k);
    int mmax   = ceil(m / (double)k);
    int totals = 0;
    for (int i = 1; i <= nmax; i++) {
        for (int j = 1; j <= mmax; j++) {
            totals += getdelta(i, j, k);
        }
    }
    return totals;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char proc;
            do {
                scanf("%c", &proc);
            } while (proc == '\n');
            pic[i][j] = pic[i - 1][j] + pic[i][j - 1] - pic[i - 1][j - 1] + proc - '0';
        }
    }
    int chvl = max(n, m) * max(n, m);
    for (int k = 2; k < max(n, m); k++) {
        chvl = min(chvl, gettotals(k));
    }
    cout << chvl;
    return 0;
}