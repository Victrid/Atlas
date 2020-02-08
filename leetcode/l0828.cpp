#include "lc.hpp"
class Solution {
public:
    struct dsts {
        int ld;
        int rd;
    };
    dsts* stringprocess(string S) {
        dsts* str = new dsts[S.length()]();
        dsts** d = new dsts*[128]();
        for(int i = 0;i<S.length();i++){
            if(d[S[i]]==nullptr){
                str[i].ld=i+1;
                str[i].rd=S.length()-i;
                d[S[i]]=(str+i);
            }else{
                str[i].ld=(str+i)-d[S[i]];
                str[i].rd=S.length()-i;
                d[S[i]]->rd=(str+i)-d[S[i]];
                d[S[i]]=(str+i);
            }
        }
        return str;
    }
    int uniqueLetterString(string S) {
        int ans = 0;
        dsts* str = stringprocess(S);
        for(int i=0;i<S.length();i++){
            ans+=str[i].ld*str[i].rd;
        }
        return ans%1000000007;
    }
};
int main(){
    Solution sol;
    cout << sol.uniqueLetterString("ABA");
    return 0;
}