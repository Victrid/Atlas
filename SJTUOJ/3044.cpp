#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << '1';
        return 0;
    }
    int* ans = new int[n + 1]();
    ans[0]   = 1;
    ans[1]   = 2;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; 2 * j <= i; j++) {
            ans[i] += ans[j];
            ans[i] %= 1000000007;
        }
    }
    cout << ans[n];
}