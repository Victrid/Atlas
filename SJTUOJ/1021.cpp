#include <iomanip>
#include <iostream>

using namespace std;
inline int& min(int& s1, int& s2) {
    return s1 < s2 ? s1 : s2;
}
int calc(int i, int j, int n) {
    int p = min(min(i, n + 1 - i), min(j, n + 1 - j));
    if (i == p)
        return j - i + 1 + 4 * (n - p + 1) * (p - 1);
    if (i == n + 1 - p)
        return 3 * n - j - 5 * p + 4 * (n - p + 1) * (p - 1) + 4;
    if (j == p)
        return j - i + 4 * n - 8 * p + 4 * (n - p + 1) * (p - 1) + 5;
    else
        return i + n - 3 * p + 4 * (n - p + 1) * (p - 1) + 2;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i)
            cout << endl;
        for (int j = 0; j < n; j++) {
            cout << setw(6) << calc(i + 1, j + 1, n);
        }
    }
    return 0;
}