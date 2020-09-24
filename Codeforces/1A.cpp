#include <iostream>
using namespace std;

#define getl(n, a) (n / a + ((n / a * a) - n != 0))

int main() {
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    cout << getl(n, a) * getl(m, a);
    return 0;
}