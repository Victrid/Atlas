#include <iostream>

using namespace std;

int main() {
    int M, T, U, F, D;
    cin >> M >> T >> U >> F >> D;

    char c;
    int tf = 0, udt = U + D, fft = F + F;
    for (int i = 0; i < T; i++) {
        cin >> c;
        if (c != 'f')
            tf += udt;
        else
            tf += fft;
        if (tf > M) {
            cout << i;
            break;
        }
    }
    return 0;
}