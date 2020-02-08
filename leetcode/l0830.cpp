#include "lc.hpp"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        char cmp  = '\0';
        int front = 0;
        for (int i = 0; i <= S.length(); i++) {
            if (S[i] != cmp) {
                if(i-front>=3){
                    vector<int> V{front,i-1};
                    ans.push_back(V);
                }
                front = i;
            }
        }
        return ans;
    }
};