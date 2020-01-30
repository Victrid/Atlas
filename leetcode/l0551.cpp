#include "lc.hpp"
class Solution
{
public:
    bool checkRecord(string s)
    {
        bool asc = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                if (asc)
                    return false;
                asc = true;
            }
            if (s[i] == 'L')
            {
                if (i >= s.length() - 2)
                    return true;
                if (s[i + 1] == 'L' && s[i + 2] == 'L')
                    return false;
            }
        }
        return true;
    }
};