#include "lc.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())return 0;
        return findMin(nums.begin(), nums.end() - 1);
    }
    int findMin(vector<int>::iterator begin, vector<int>::iterator end) {
        // *begin>=*end,or not rotated.
        if (*begin < *end)
            return *begin;
        if(begin==end)return *begin;
        if(end-begin==1)return *end;
        auto mid = begin + (end - begin) / 2;
        if (*mid<*end)return findMin(begin,mid);
        else if(*mid>*end)return findMin(mid,end);
        else return findMin(begin,end-1);
    }
};