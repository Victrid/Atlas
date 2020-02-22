#include "lc.hpp"
//! error

class Solution {
public:
    inline int comb(int i) {
        if (i <= 1)
            return 0;
        return i * (i - 1) / 2;
    }
    int numberOfSubstrings(string s) {
        int abccount   = 0;
        bool a         = false;
        bool b         = false;
        bool c         = false;
        int i          = s.size() - 1;
        int z[3]       = {0, 0, 0};
        int roundcount = 0;
        for (; i >= 0; i--) {
            switch (s[i]) {
            case 'a':
                z[roundcount % 3] = 'a';
                roundcount++;
                break;
            case 'b':
                z[roundcount % 3] = 'b';
                roundcount++;
                break;
            case 'c':
                z[roundcount % 3] = 'c';
                roundcount++;
                break;
            }
            if (roundcount == 3) {
                abccount++;
                break;
            }
        }
        for (; i >= 0; i--) {
            if (s[i] == z[0]) {
                abccount++;
                z[0] = z[1];
                z[1] = z[2];
                z[2] = s[i];
            }
        }
        if (abccount == 0)
            return 0;
        return abccount * (s.size() - 2) - comb(abccount);
    }
};
int main() {
    string a = "abcabc";
    Solution Sol;
    Sol.numberOfSubstrings(a);
    return 0;
}