#include "lc.hpp"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum    = nums[0];
        int maxsum = sum;
        for (int i = 1; i < nums.size(); i++) {
            sum    = (sum < 0) ? nums[i] : sum + nums[i];
            maxsum = (maxsum > sum) ? maxsum : sum;
        }
        return maxsum;
    }
};