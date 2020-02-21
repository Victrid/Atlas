#include "lc.hpp"
// * like math induction
// 2 will Alice win.
// for every number N with a certain
// result, N+1 can assume x as 1
// and the result is reversed.
class Solution {
public:
    bool divisorGame(int N) {
        return !(N%2);
    }
};