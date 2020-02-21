#include "lc.hpp"
//0.2 82.15% time 9.41% memory
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto it = nums.begin();
        int sum = 0;
        for (; it < nums.end(); it++)
            sum += *it;
        if (sum & 1)
            return false;
        //计算目标和,建立数组。
        bool** b = new bool*[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++) {
            b[i] = new bool[sum / 2 + 1];
        }

        //第一行的设置
        b[0][0] = true;
        for (int j = 1; j <= sum / 2; j++) {
            b[0][j] = false;
        }

        //接下来的各行
        for (int i = 1; i <= nums.size(); i++) {
            //将上一行为true的对应的和的格子置true。
            for (int j = 0; j <= sum / 2; j++)
                b[i][j] = b[i - 1][j];

            //将上一行为true对应的和加上新增的集合元素值所得到的和对应的格子置true
            for (int j = 0; j <= sum / 2; j++)
                if (b[i - 1][j] && j + nums[i - 1] <= sum / 2)
                    b[i][j + nums[i - 1]] = true;

            //判断目标和的格子是否为true。如果true出现那么返回true。
            if (b[i][sum / 2])
                return true;
        }
        //全部遍历目标和格子仍然为false，我们返回false。
        return false;
    }
};
