#include "lc.hpp"
//0.1 divide and conquer TLE
class Solution {
public:
    bool canPartition(vector<int>::iterator it, vector<int>::iterator rr, int sum) {
        if (it == rr)
            return false;
        if (*it == sum)
            return true;
        if (*it > sum)
            return false;
        return canPartition(it + 1, rr, sum - *it) || canPartition(it + 1, rr, sum);
    }

    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        if (sum & 1)
            return false;
        it      = nums.begin();
        auto rr = nums.end();
        return canPartition(it, rr, sum / 2);
    }
};
