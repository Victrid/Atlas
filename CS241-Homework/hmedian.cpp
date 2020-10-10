#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    float hMedian(vector<int> citations) {
        MergeSort(citations);
        auto hindex = hIndex(citations);
        if (hindex == 0)
            return 0;
        if (hindex % 2 == 0)
            return (citations[hindex / 2 - 1] + citations[hindex / 2]) / 2.0;
        else
            return citations[hindex / 2];
    }

private:
    int hIndex(const vector<int>& citations) {
        int idx = 0;
        for (; idx < citations.size(); ++idx)
            if (citations[idx] < idx + 1)
                break;
        return idx;
    }

    void MergeSort(vector<int>& citations) {
        return MergeSort(citations.begin(), citations.end());
    }

    void MergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
        auto dist = end - begin;
        if (dist == 0 || dist == 1)
            return;
        if (dist == 2) {
            if (*begin < *(end - 1))
                swap(*begin, *(end - 1));
            return;
        }
        MergeSort(begin, begin + dist / 2);
        MergeSort(begin + dist / 2, end);
        vector<int> temp(end - begin);
        auto l = begin, r = begin + dist / 2, v = temp.begin();
        while (l != begin + dist / 2 && r != end)
            if (*l > *r)
                *v = *l, v++, l++;
            else
                *v = *r, v++, r++;
        while (l != begin + dist / 2)
            *v = *l, v++, l++;
        while (r != end)
            *v = *r, v++, r++;
        v = temp.begin();
        while (begin != end)
            *begin = *v, begin++, v++;
        return;
    }
};

int main(int argc, char** argv) {
    std::string line;
    int number;
    std::vector<int> numbers;

    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);

    Solution s;
    float res = s.hMedian(numbers);

    std::cout << std::fixed;
    std::cout << std::setprecision(1) << res << endl;

    return 0;
}
