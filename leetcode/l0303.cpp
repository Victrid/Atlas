#include "lc.hpp"
class NumArray {
private:
    vector<int> sum;

public:
    NumArray(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if (sum.size() == 0)
            return 0;
        if (!i)
            return sum[j];
        return sum[j] - sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */