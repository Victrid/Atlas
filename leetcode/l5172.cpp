#include "lc.hpp"
//!error
class Solution {
public:
    static inline bool dec(int& i, int& j) {
        return i > j;
    }
    bool comp(string& ll, string& rr, int digit) {
        if (ll.size() > rr.size() + 1)
            return true;
        if (ll.size() < rr.size() + 1)
            return false;
        for (int i = 0; i < rr.size(); i++) {
            if (ll[i] > rr[i])
                return true;
            if (ll[i] < rr[i])
                return false;
        }
        if (ll[rr.size()] > digit + '0')
            return true;
        return false;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), dec);
        vector<string> aa(3), bb(3);
        aa[0]         = {};
        aa[1]         = {};
        aa[2]         = {};
        bool found[3] = {false, false, false};
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (!(digits[i] % 3)) {
                    bb[j].push_back(digits[i]+'0');
                    found[0]=true;
                    continue;
                }
                if (comp(aa[j], aa[(12 + j - digits[i]) % 3], digits[i])) {
                    bb[j] = aa[j];
                } else {
                    if (!found[j]) {
                        if (digits[i] % 3 == j) {
                            bb[j].push_back(digits[i] + '0');
                            found[j] = true;
                        } else
                            bb[j] = aa[j];
                    } else {
                        bb[j] = aa[(12 + j - digits[i]) % 3];
                        bb[j].push_back(digits[i] + '0');
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                aa[i] = bb[i];
            }
        }
        return aa[0];
    }
};