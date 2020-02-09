#include "lc.hpp"

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