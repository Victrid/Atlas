#include "lc.hpp"

//* It's slow, as it sorts every change, causing the time complecity
//* at O(n^2lgn). Using a heap, or priority list can reduce
//* the time greatly.

class Solution {
public:
    bool isPossible(vector<int>& target) {
        sort(target.begin(), target.end());
        while (target.front() != 1 || target.back() != 1) {
            for (auto it = target.begin(); it < target.end() - 1; it++) {
                target.back() -= *it;
                if (target.back() < 1)
                    return false;
            }
            sort(target.begin(), target.end());
        }
        return true;
    }
};
