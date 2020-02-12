#include "lc.hpp"
class Solution {
public:
    int tribonacci(int n) {
        int step[] = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            step[i % 3] += step[(i + 1) % 3];
            step[i % 3] += step[(i + 2) % 3];
        }
        return step[n % 3];
    }
};