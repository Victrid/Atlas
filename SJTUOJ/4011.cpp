#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
class ulll {
private:
    unsigned long long data[20];
    int getDigitNum(unsigned long long n) const {
        int dig = 1;
        if (n >= 10000000000000000ull) {
            n /= 10000000000000000ull;
            dig += 16;
        }
        if (n >= 100000000ull) {
            n /= 100000000ull;
            dig += 8;
        }
        if (n >= 10000ull) {
            n /= 10000ull;
            dig += 4;
        }
        if (n >= 100ull) {
            n /= 100ull;
            dig += 2;
        }
        while (n >= 10ull) {
            n /= 10ull;
            dig += 1;
        }
        return dig;
    }

public:
    operator bool() const {
        for (int i = 19; i >= 0; i--) {
            if (data[i] != 0)
                return true;
        }
        return false;
    }
    ulll() {
        for (int i = 0; i < 20; i++) {
            data[i] = 0;
        }
    }
    ulll(long long init) {
        for (int i = 1; i < 20; i++) {
            data[i] = 0;
        }
        data[0] = abs(init);
        return;
    }
    ulll& operator+=(const ulll& rhs) {
        for (int i = 0; i < 20; i++) {
            data[i] += rhs.data[i];
            while (i != 19 && data[i] >= 10000000000000000000ull) {
                data[i + 1] += 1;
                data[i] -= 10000000000000000000ull;
            };
        }
        return *this;
    }
    void print() const {
        bool nof = 0;
        if (!*this) {
            putchar('0');
            return;
        }
        for (int i = 19; i >= 0; i--) {
            if (!nof && data[i] == 0)
                continue;
            if (nof) {
                int p = 19 - getDigitNum(data[i]);
                while (p--)
                    putchar('0');
            }
            nof = 1;
            printf("%llu", data[i]);
        }
        return;
    }
};

ulll k_h[55][55];

ulll DP(int d, int h, int k) {
    if (k_h[d][h])
        return k_h[d][h];
    if (h == 2) {
        k_h[d][h] = d;
        return k_h[d][h];
    }
    for (int i = 0; i < d; i++) {
        k_h[d][h] += DP(k - i, h - 1, k);
    }
    return k_h[d][h];
}
int main() {
    int k, h;
    scanf("%d%d", &k, &h);
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            k_h[i][i] = 0;
        }
    }
    DP(k, h, k).print();
    return 0;
}