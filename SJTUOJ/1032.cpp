#include <iostream>
using namespace std;

long long int A(long long int m, long long int n) {
    if (m == 0)
        return (n + 1);
    if (n == 0)
        return A(m - 1, 1);
    else
        return A(m - 1, A(m, n - 1));
}
int main() {
    long long int m, n;
    cin >> m >> n;
    cout << A(m, n);
}