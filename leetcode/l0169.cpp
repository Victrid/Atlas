#include "lc.hpp"
class Solution {
public:
    // using mole vote method
    int majorityElement(vector<int>& nums) {
        vector<int>::iterator ref = nums.begin();
        int count                 = 1;
        for (vector<int>::iterator i =
                 nums.begin() + 1;
             i < nums.end(); i++) {
            if (*i == *ref)
                count++;
            else
                count--;
            if (count < 0) {
                ref   = i;
                count = 1;
            }
        }
        return *ref;
    }
};