#include <iostream>
using namespace std;
int dremainder[] = {0, 1, 3, 6, 0, 5, 1, 8, 6, 5};
int main() {
    int total = 0;
    cin >> total;
    long long* ans = new long long[total];
    long long* dig = new long long[total];
    for (int i = 0; i < total; i++) {
        cin >> ans[i];
        long long proc      = ans[i];
        short lowestdigitpo = (proc + 1) % 10;
        //lowest digit self's added + n x {123456789} time (mod===5)
        ans[i] = (dremainder[proc % 10] + (proc / 10 % 2) * 5) % 10;
        proc /= 10;
        //higher digits
        long long zeroph = 1;

        for (int j = 0; proc != 0; j++) {
            zeroph *= 10;
            int procdigit = proc % 10;
            proc /= 10;
            // 123 >4< 5: 4~{0,1,2,3,4,5}
            // lowest digit +1: really effected numbers.
            procdigit = procdigit * lowestdigitpo % 10;
            ans[i] += procdigit * zeroph;
        }
        dig[i] = zeroph / 10;
    }
    for (int i = 0; i < total; i++) {
        if (i)
            cout << endl;
        //! CYKA BLYAT padding zeros
        //errare
        // if (ans[i] == 0) {
        //     cout << '0';
        //     continue;
        // }
        //errare 2
        // while (ans[i] < dig[i]) {
        //     cout << '0';
        //     dig[i] /= 10;
        // }
        cout << ans[i];
    }
    return 0;
}