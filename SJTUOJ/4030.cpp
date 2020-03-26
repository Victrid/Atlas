#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    double* P = new double[N + 1];
    //single shot
    double* Eh = new double[N + 1];
    double* E  = new double[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    P[0]  = 0;
    E[0]  = 0;
    Eh[0] = 0;
    for (int i = 1; i <= N; i++) {
        Eh[i] = (Eh[i - 1] + 1) * P[i - 1] + 1;
        E[i]  = E[i - 1] + Eh[i] * P[i];
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << E[N];
    return 0;
}