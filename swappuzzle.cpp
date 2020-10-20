#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// the matrix's rank
const int RANK  = 3;
const int TOTAL = RANK * RANK;

// variables used in A*
// cart is the eval distance and rdist is the real distance.
const int cart  = 0;
const int rdist = 1;

template <int N> struct status;
template <int N> struct childposition { status<N>* val[4]; };

template <int N> struct status {
    status<N>* parent;
    int value[N * N];
    int real_distance;
    unsigned long long matrix_hash() {
        unsigned long long hash = 0;
        for (int i = 0; i < N * N; i++) {
            hash = (hash * 131) + value[i];
        }
        return hash;
    }
    status() : parent(nullptr), real_distance(0) {}
    status(status& st) : parent(&st), real_distance(st.real_distance + 1) {
        for (int i = 0; i < N * N; i++) {
            value[i] = st.value[i];
        }
    }
    inline int get_zero_pos() {
        for (int ploc = 0; ploc < N * N; ploc++)
            if (value[ploc] == 0)
                return ploc;
        return -1;
    }
    childposition<N> get_childrens() {
        int ploc = get_zero_pos();
        childposition<N> pt;
        int l = ploc / N, r = ploc % N;
        if (l + 1 < N)
            pt.val[0] = new status(*this),
            swap(pt.val[0]->value[ploc], pt.val[0]->value[ploc + N]);
        else
            pt.val[0] = nullptr;
        if (r + 1 < N)
            pt.val[1] = new status(*this),
            swap(pt.val[1]->value[ploc], pt.val[1]->value[ploc + 1]);
        else
            pt.val[1] = nullptr;
        if (l - 1 >= 0)
            pt.val[2] = new status(*this),
            swap(pt.val[2]->value[ploc], pt.val[2]->value[ploc - N]);
        else
            pt.val[2] = nullptr;
        if (r - 1 >= 0)
            pt.val[3] = new status(*this),
            swap(pt.val[3]->value[ploc], pt.val[3]->value[ploc - 1]);
        else
            pt.val[3] = nullptr;
        return pt;
    }
    int cartesian_std() {
        int retval = 0;
        for (
            int i = 0; i < N * N; [&](int val, int pos) {
                val = val == 0 ? 8 : val - 1;
                retval += abs(val / N - pos / N) + abs(val % N - pos % N);
            }(value[i], i),
                i++)
            ;
        return retval;
    }
};
struct cmp {
    bool operator()(status<RANK>* l, status<RANK>* r) {
        return cart * l->cartesian_std() + rdist * l->real_distance >
               cart * r->cartesian_std() + rdist * r->real_distance;
    };
};
int main() {
    set<unsigned long long> visited;
    int stdhash;
    status<RANK> standard, initstat;
    status<RANK>* fin = nullptr;
    priority_queue<status<RANK>*, vector<status<RANK>*>, cmp> searchqueue;
    stack<int> st;
    for (int i = 0; i < TOTAL - 1; i++)
        standard.value[i] = i + 1;
    standard.value[TOTAL - 1] = 0;

    stdhash = standard.matrix_hash();
    for (int i = 0; i < TOTAL; i++)
        cin >> initstat.value[i];
    searchqueue.push(&initstat);
    visited.insert(initstat.matrix_hash());
    int t = 0;
    while (!searchqueue.empty()) {
        t++;
        status<RANK>* cur = searchqueue.top();
        searchqueue.pop();
        auto sons = cur->get_childrens();
        for (int i = 0; i < 4; i++) {
            if (sons.val[i] == nullptr)
                continue;
            int hash = sons.val[i]->matrix_hash();
            if (visited.find(hash) != visited.end())
                continue;
            if (hash == stdhash) {
                fin = sons.val[i];
                goto end;
            }
            searchqueue.push(sons.val[i]);
            visited.insert(hash);
        }
    }
    return -1;
end:;
    while (fin->parent != nullptr)
        st.push(fin->parent->value[fin->get_zero_pos()]), fin = fin->parent;
    cout << "Steps: " << endl;
    int p = 0;
    while (!st.empty())
        p++, cout << st.top() << (p % 4 != 0 ? ' ' : '\n'), st.pop();
    cout << endl << "Searched: " << t << " ,Steps: " << p << endl;
    return 0;
}
