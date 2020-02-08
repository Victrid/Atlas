#include "lc.hpp"
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mrtpi = minutes * 6;
        double hrtpi = hour * 30 + minutes / 2.0;
        double angle = hrtpi - mrtpi;
        if (angle < 0)
            angle = -angle;
        if (angle > 180)
            angle = 360 - angle;
        return angle;
    }
};