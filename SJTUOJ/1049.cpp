#include <cstdio>
#include <iostream>
using namespace std;

template <typename T>
class basestack {
private:
    T container[1000] = {0};
    T* top_ptr;
    int total;
    bool balance_changed;

public:
    basestack() {
        top_ptr = container;
        total   = 0;
    }
    int height() { return total; }
    T push(T p) {
        *top_ptr = p;
        top_ptr++;
        total++;
        return *(top_ptr - 1);
    }
    T top() { return total ? *(top_ptr - 1) : -1; }
    T pop() {
        if (total == 0)
            return *top_ptr;
        top_ptr--;
        total--;
        return *(top_ptr - 1);
    }
    void clear() {
        top_ptr = container;
        total   = 0;
    }
};
bool ans[300];
int proc[1001];
basestack<int> stk;
int T, N, M, now, nums;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        stk.clear();
        now    = 0;
        nums   = 0;
        ans[i] = true;
        for (int j = 0; j < N; j++)
            scanf("%d", &proc[j]);
        while (nums != N) {
            if (proc[nums] == now) {
                nums++;
                now++;
                continue;
            }
            if (proc[nums] == stk.top()) {
                nums++;
                stk.pop();
                continue;
            }
            stk.push(now++);
            if (stk.height() == M + 1) {
                ans[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < T; i++)
        printf(ans[i] ? "YES\n" : "NO\n");
    return 0;
}