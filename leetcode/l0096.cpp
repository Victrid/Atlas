#include "lc.hpp"
class Solution {
public:
    int Catalan(int n) {
        vector<int> ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                ans[i]+=ans[j-1]*ans[i-j];
            }
        }
        return ans[n];
    }
    int numTrees(int n) {
        return Catalan(n);
    }
};