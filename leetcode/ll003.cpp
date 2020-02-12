#include "lc.hpp"
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> u;
        auto it = nums.begin();
        for(;it<nums.end();it++){
            if(u.find(*it)==u.end()){
                u[*it]=true;
            }
            else return *it;
        }
        return 0;
    }
};