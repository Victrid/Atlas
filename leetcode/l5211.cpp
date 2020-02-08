#include "lc.hpp"

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0)
            return 0;
        int cnt = -1;
        while (num != 0) {
            if (num % 2) {
                cnt++;
            }
            cnt++;
            num >>= 1;
        }
        return cnt;
    }
};