#include "lc.hpp"
//fast and neat
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        if (sum & 1)
            return false;
        //建立一个一维bool数组
        bool* boolarray = new bool[sum + 1]();
        sum >>= 1;
        for (it = nums.begin(); it < nums.end(); it++) {
            //原本为true对应的和加新增值置true
            for (int j = sum; j >= 0; j--)
                if (boolarray[j])
                    boolarray[j + *it] = 1;
            //自己置true
            boolarray[*it] = 1;
            //判断目标和
            if (boolarray[sum])
                return true;
        }
        //目标和格子仍然为false，我们返回false。
        return false;
    }
};