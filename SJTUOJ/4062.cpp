#include <iostream>
using namespace std;
long long seq(long long x, long long y) {
    if (x < y)
        return seq(y, x);
    if (y == 0)
        return 0;
    return x / y * 4 * y + seq(y, x % y);
}
int main() {
    long long x, y;
    cin >> x >> y;
    cout << seq(x, y);
    return 0;
}