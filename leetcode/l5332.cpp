//!wrong
#include "lc.hpp"
class Solution {
public:
    bool find(vector<int>::iterator begin, vector<int>::iterator end, double s) {
        if (end - begin == 0)
            return false;
        if (*begin > s || *end < s)
            return false;
        if (*begin == s || *end == s)
            return true;

        auto mid = begin + (end - begin) / 2;
        return find(begin, mid, s) || find(mid + 1, end, s);
    }
    bool checkIfExist(vector<int>& arr) {
        if (arr.begin() == arr.end())
            return false;
        sort(arr.begin(), arr.end());
        for (auto i = arr.end() - 1; i > arr.begin(); i--) {
            int z = *i;
            i     = arr.erase(i);
            if (z > 0 && find(arr.begin(), arr.end()-1, z / 2.0))
                return true;
            if (z == 0 && find(arr.begin(), arr.end()-1, 0))
                return true;
            if (z < 0 && find(arr.begin(), arr.end()-1, z * 2))
                return true;
        }
        return false;
    }
};
int main() {
    vector<int> a = {0,0};
    Solution S;
    S.checkIfExist(a);
    return 0;
}