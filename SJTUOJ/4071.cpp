#include <cstdio>
#include <iostream>
#define mod 1000000007LL
using namespace std;
struct matrix {
    long long a1, a2, b1, b2;
    matrix operator*(const matrix& rhs) {
        return matrix{(a1 * rhs.a1 + a2 * rhs.b1) % mod, (a1 * rhs.a2 + a2 * rhs.b2) % mod, (b1 * rhs.a1 + b2 * rhs.b1) % mod, (b1 * rhs.a2 + b2 * rhs.b2) % mod};
    }
};
matrix fibo{1, 1, 1, 0};
matrix init{1, 0, 0, 1};
int main() {
    long long n;
    scanf("%lld", &n);
    for (long long i = n - 1; i; i >>= 1) {
        if (i & 1LL)
            init = fibo * init;
        fibo = fibo * fibo;
    }
    printf("%lld", (init.a1 + init.a2) % mod);
    return 0;
}