#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

inline bool valid_messi(int** mat, int n1, int m1, int n, int m) {
    return n1 < n && n1 >= 0 && m1 < m && m1 >= 0 && (mat[n1][m1] == 0 || mat[n1][m1] == 1);
}
inline bool valid_door(int** mat, int n1, int m1, int n, int m) {
    return n1 < n && n1 >= 0 && m1 < m && m1 >= 0 && (mat[n1][m1] == 0 || mat[n1][m1] == 1 || mat[n1][m1] == 3);
}
bool check() {
    int n, m;
    cin >> n >> m;
    int** inputmat = new int*[n];
    for (int i = 0; i < n; i++) {
        inputmat[i] = new int[m]();
        for (int j = 0; j < m; j++)
            cin >> inputmat[i][j];
    }
    stack<int> lll;
    stack<int> rrr;
    lll.push(0);
    rrr.push(0);
    while (!lll.empty()) {
        int n0 = lll.top();
        int m0 = rrr.top();
        lll.pop();
        rrr.pop();
        if (n0 == n - 1 && m0 == m - 1)
            return true;
        if (inputmat[n0][m0] == 0) {
            if (valid_messi(inputmat, n0 + 1, m0, n, m)) {
                lll.push(n0 + 1);
                rrr.push(m0);
            }
            if (valid_messi(inputmat, n0, m0 + 1, n, m)) {
                lll.push(n0);
                rrr.push(m0 + 1);
            }
            if (valid_messi(inputmat, n0, m0 - 1, n, m)) {
                lll.push(n0);
                rrr.push(m0 - 1);
            }
            if (valid_messi(inputmat, n0 - 1, m0, n, m)) {
                lll.push(n0 - 1);
                rrr.push(m0);
            }
            inputmat[n0][m0] = 2;
        }
        if (inputmat[n0][m0] == 1) {
            inputmat[n0][m0] = 3;
        }
    }
    lll.push(n - 1);
    rrr.push(m - 1);
    while (!lll.empty()) {
        int n0 = lll.top();
        int m0 = rrr.top();
        lll.pop();
        rrr.pop();
        if (inputmat[n0][m0] == 3)
            return true;
        if (inputmat[n0][m0] == 0) {
            if (valid_door(inputmat, n0 + 1, m0, n, m)) {
                lll.push(n0 + 1);
                rrr.push(m0);
            }
            if (valid_door(inputmat, n0, m0 + 1, n, m)) {
                lll.push(n0);
                rrr.push(m0 + 1);
            }
            if (valid_door(inputmat, n0, m0 - 1, n, m)) {
                lll.push(n0);
                rrr.push(m0 - 1);
            }
            if (valid_door(inputmat, n0 - 1, m0, n, m)) {
                lll.push(n0 - 1);
                rrr.push(m0);
            }
            inputmat[n0][m0] = 4;
        }
        if (inputmat[n0][m0] == 1) {
            inputmat[n0][m0] = 5;
        }
    }
    return false;
}
int main() {
    int totalis;
    int* ii = new int[totalis];
    cin >> totalis;
    for (int i = 0; i < totalis; i++) {
        ii[i] = check();
    }
    for (int i = 0; i < totalis; i++) {
        if (i)
            cout << endl;
        cout << to_string(ii[i]);
    }
    return 0;
}