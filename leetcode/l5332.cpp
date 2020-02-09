#include "lc.hpp"

/* 大佬用暴力法，是因为大佬知道暴力可以直接AC而不会TLE。

我看到可以暴力解决的题目，总是担心TLE，就把自己绕进去，写一些复杂度等价的垃圾代码，一个题写一个小时，还总是卡边界。

当我只能暴力解决的时候，每次都是TLE。

我太弱了[快哭了][快哭了] */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int l = arr.size();
        for (int i = 0; i < l; i++)
            for (int j = i + 1; j < l; j++)
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                    return true;
        return false;
    }
};