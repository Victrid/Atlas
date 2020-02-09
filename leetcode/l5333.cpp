#include "lc.hpp"
class Solution {
public:
    int minSteps(string s, string t) {
        int count[128]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(count[s[i]])count[s[i]]--;
        }
        int countt = 0;
        for(int i=0;i<128;i++){
            countt+=count[i];
        }
        return countt;
    }
};