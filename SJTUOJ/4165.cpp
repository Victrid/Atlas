#include <iostream>
using namespace std;
inline int sgn(int& a) {
    if (a == 0)
        return 0;
    if (a > 0)
        return 1;
    if (a < 0)
        return -1;
    return 0;
}
int main() {
    int n;
    cin >> n;
    int* list = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    int proc;
    for (int i = 0; i < n; i++) {
        cin >> proc;
        list[i] -= proc;
    }
    int sign            = 0;
    int height          = 0;
    long long totalstep = 0; //???
    for (int i = 0; i < n; i++) {
        if (sign != sgn(list[i])) {
            height = sgn(list[i]) * list[i];
            sign   = sgn(list[i]);
            totalstep += height;
            continue;
        }
        if (sgn(list[i]) * list[i] > height) {
            totalstep += (sgn(list[i]) * list[i] - height);
            height = sgn(list[i]) * list[i];
            continue;
        }
        if (sgn(list[i]) * list[i] <= height) {
            height = sgn(list[i]) * list[i];
            continue;
        }
    }
    cout << totalstep;
    return 0;
}