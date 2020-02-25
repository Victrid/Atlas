#include "lc.hpp"
//!TLE
class Solution {
public:
    int delta(int num, int i) {
        int delta = 0;
        for(;i+delta<=num;delta++){
            if(!(num%(i+delta)))return i+delta;
        }
        return num;
    }

    vector<int> closestDivisors(int num) {
        int i1 = ceil(sqrt(num + 1));
        int i2 = ceil(sqrt(num + 2));
        int j1 = delta(num+1,i1);
        int j2 = delta(num+2,i2);
        vector<int> aa;
        if((j1-(num+1)/j1)>(j2-(num+2)/j2)){
            aa.push_back(j2);
            aa.push_back((num+2)/j2);
        }else{
            aa.push_back(j1);
            aa.push_back((num+1)/j1);
        }
        return aa;
    }
};