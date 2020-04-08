#include <cstdio>
#include <iostream>
using namespace std;
//Changed logic to avoid duplicats.
//NO WA please🙏
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int proc[1000000];
int stk[1000000];
int* stkptr = stk;
int T, N, now;
int main() {
    T = read();
    while (T--) {
        N      = read();
        stkptr = stk;
        now    = 0;
        for (int j = 0; j < N; j++)
            proc[j] = read();
        for (int nums = 1; nums <= N; ++nums) {
            *stkptr++ = nums;
            while (stkptr != stk && now < N && proc[now] == stkptr[-1]) {
                stkptr--;
                now++;
            }
        }
        printf(stkptr == stk ? "Yes\n" : "No\n");
    }
    return 0;
}