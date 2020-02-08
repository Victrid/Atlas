#include "lc.hpp"
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if (k > arr.end() - arr.begin())
            return 0;
        int summin              = threshold * k;
        int suminit             = 0;
        int count               = 0;
        vector<int>::iterator a = arr.begin();
        for (int i = 0; i < k; i++) {
            suminit += *a;
            a++;
        }
        if (suminit >= summin)
            count++;
        for (; a < arr.end(); a++) {
            suminit -= *(a - k);
            suminit += *a;
            if (suminit >= summin)
                count++;
        }
        return count;
    }
};