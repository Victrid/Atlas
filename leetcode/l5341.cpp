#include "lc.hpp"
class ProductOfNumbers {
private:
    vector<int> numbers;
    int store_k   = 0;
    int store_ans = 0;
    bool stored   = false;

public:
    ProductOfNumbers() {
        numbers.clear();
        stored = false;
    }

    void add(int num) {
        numbers.push_back(num);
        stored = false;
    }

    int getProduct(int k) {
        // * cache responcing to
        // * same requests.
        if (store_k != k)
            stored = false;
        if (stored)
            return store_ans;
        store_k = k;
        stored  = true;
        auto it = numbers.rbegin();
        int ans = 1;
        while (k > 0) {
            // * skip 1
            if (*it != 1) {
                ans *= *it;
            }
            it++;
            k--;
        }
        store_ans = ans;
        return ans;
    }
};