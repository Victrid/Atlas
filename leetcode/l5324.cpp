#include "lc.hpp"
class Cashier {
public:
    int nn;
    int count;
    int d;
    unordered_map<int, int> valmap;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        nn    = n;
        count = 1;
        d     = discount;
        int i = products.size() - 1;
        for (; i >= 0; i--) {
            valmap[products[i]] = prices[i];
        }
        return;
    }

    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        for (int i = amount.size() - 1; i >= 0; i--) {
            total += valmap[product[i]] * amount[i];
        }
        if(!(count%nn))total -= (d * total) / 100.0;
        count++;
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */