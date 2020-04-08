#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long n, a, b, x1, y1, x2, y2;
    cin >> n;
    while (n--) {
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        cout << (long long)max(abs(floor((x1 + y1) / (double)(2 * a)) - floor((x2 + y2) / (double(2 * a)))), abs(floor((x1 - y1) / (double)(2 * b)) - floor((x2 - y2) / (double(2 * b))))) << endl;
    }
    return 0;
}