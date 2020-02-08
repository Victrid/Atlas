#include "lc.hpp"

class Solution {
public:
    inline int find(string S, char c) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == c)
                return i;
        }
        return -1;
    }
    string maskPII(string S) {
        if (find(S, '@') != -1) {
            //email
            int last = find(S, '@') - 1;
            string ret;
            ret += S[0];
            ret += "*****";
            ret += S.substr(last);
            for (int i = 0; i < ret.length(); i++) {
                if(ret[i]>='A'&&ret[i]<='Z'){
                    ret[i]-=('A'-'a');
                }
            }
            return ret;
        } else {
            //tel
            int digit = 0;
            string ret;
            while (S.length()) {
                char C = S.back();
                if (C <= '9' && C >= '0') {
                    //digit
                    ret.push_back(C);
                    digit++;
                } else {
                }
                S.pop_back();
            }
            string retl;
            if (digit == 10) {
                retl += "***-***-";
            } else if (digit == 11) {
                retl += "+*-***-***-";
            } else if (digit == 12) {
                retl += "+**-***-***-";
            } else {
                retl += "+***-***-***-";
            }
            retl += ret[3];
            retl += ret[2];
            retl += ret[1];
            retl += ret[0];
            return retl;
        }
    }
};