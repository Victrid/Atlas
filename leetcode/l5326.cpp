#include "lc.hpp"

class Solution {
public:
    int countOrders(int n) {
        long long* ans = new long long[n + 1];
        ans[1]         = 1;
        for (int i = 2; i < n + 1; i++) {
            ans[i] = ans[i - 1] * (2 * i - 1 + (2 * i - 1) * (2 * i - 2) / 2) % 1000000007;
        }
        return ans[n];
    }
};