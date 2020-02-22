#include "lc.hpp"

class Solution {
public:
    int massage(vector<int>& nums) {
        int i = nums.size()+2;
        int *best = new int[i];
        best[0]=0;
        best[1]=0;
        for(int j=2;j<i;j++){
            best[j]=(nums[j-2]+best[j-2]>best[j-1])?nums[j-2]+best[j-2]:best[j-1];
        }
        return best[i-1];
    }
};