#include "lc.hpp"
class Solution
{
public:
    int checkRecord(int n)
    {
        if (n == 1)
            return 3;
        if (n <= 0)
            return 0;
        return 3 * checkRecord(n - 1) - (n - 1) - checkRecord(n - 2);
    }
};