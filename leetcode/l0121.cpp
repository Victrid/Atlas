#include "lc.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mmin   = numeric_limits<int>::max();
        int profit = 0;
        int i      = prices.size();
        for (int j = 0; j < i; j++) {
            mmin   = mmin > prices[j] ? prices[j] : mmin;
            profit = profit > (prices[j] - mmin) ? profit : prices[j] - mmin;
        }
        return profit;
    }
};