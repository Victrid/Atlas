#include "lc.hpp"

class Solution {
public:
    int minArray(vector<int>& nums) {
        if(nums.empty())return 0;
        return minArray(nums.begin(), nums.end() - 1);
    }
    int minArray(vector<int>::iterator begin, vector<int>::iterator end) {
        // *begin>=*end,or not rotated.
        if (*begin < *end)
            return *begin;
        if(begin==end)return *begin;
        if(end-begin==1)return *end;
        auto mid = begin + (end - begin) / 2;
        if (*mid<*end)return minArray(begin,mid);
        else if(*mid>*end)return minArray(mid,end);
        else return minArray(begin,end-1);
    }
};