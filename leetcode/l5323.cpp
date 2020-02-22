#include "lc.hpp"

class Solution {
public:
    static bool compare(int& i1,int& i2){
        bitset<33> i1c(i1);
        bitset<33> i2c(i2);
        if(i1c.count()<i2c.count())return true;
        if(i1c.count()>i2c.count())return false;
        return i1 < i2;

    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};