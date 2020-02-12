#include "lc.hpp"
class Solution {
public:
    int fib(int n) {
        int step[] = {0, 1};
        for (int i = 2; i <= n; ++i) {
            step[i % 2] += step[(i + 1) % 2];
            step[i % 2] %= 1000000007;
        }
        return step[n % 2];
    }
};