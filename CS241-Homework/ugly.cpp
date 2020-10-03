#include <iostream>
using namespace std;

#define min(a, b) ((a) > (b) ? (b) : (a))

class Solution {
public:
    int nthUglyNumber(int n) {
        int* dp = new int[n];
        dp[0]   = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]);
            p2 += dp[i] == 2 * dp[p2];
            p3 += dp[i] == 3 * dp[p3];
            p5 += dp[i] == 5 * dp[p5];
        }
        int t = dp[n - 1];
        delete[] dp;
        return t;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.nthUglyNumber(n) << endl;
    return 0;
}