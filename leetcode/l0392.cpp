#include "lc.hpp"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        if (t[0] != '\0' && s[0] != '\0')
            return true;
        for (; t[j] != '\0'; j++) {
            if (t[j] == s[i]) {
                i++;
            }
            if (s[i] == '\0')
                return true;
        }
        return false;
    }
};