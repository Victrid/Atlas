#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

double washup(double d) {
    if (fabs(d - (int)d) < FLT_EPSILON)
        return (int)(d);
    if (fabs(d - ((int)d + 1)) < FLT_EPSILON)
        return ((int)d + 1);
    if (fabs(d - ((int)d - 1)) < FLT_EPSILON)
        return ((int)d - 1);
    return d;
}

int main() {
    string str;
    vector<vector<double>> mat;
    int cptr = 0, rptr = 0, residual = 0;
    double temp;
    bool fail = false;
    // Input processing.
    while (getline(cin, str)) {
        stringstream xstr(str);
        mat.push_back(vector<double>());
        while (xstr >> temp)
            mat.back().push_back(temp);
    }
    // Solve the linear system and print the results.

    while (cptr != mat.size() && rptr != mat.front().size()) {
        if (mat[cptr][rptr] == 0) {
            for (int t = cptr + 1; t != mat.size(); t++)
                if (mat[t][rptr] != 0) {
                    swap(mat[cptr], mat[t]);
                    continue;
                }
            rptr++;
            continue;
        }
        temp = 1.0 / mat[cptr][rptr];
        for (int i = 0; i != mat[cptr].size(); i++)
            mat[cptr][i] = washup(mat[cptr][i] * temp);

        for (int i = 0; i < mat.size(); i++) {
            if (i == cptr)
                continue;
            temp = mat[i][rptr];
            for (int j = 0; j < mat[i].size(); j++)
                mat[i][j] = washup(mat[i][j] - temp * mat[cptr][j]);
        }
        cptr++;
        rptr++;
    }

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size() - 1; j++) {
            if (mat[i][j] != 0) {
                residual++;
                goto con; // outside for continue
            }
        }
        if (mat[i].back() != 0) {
            fail = true;
            break;
        }
    con:;
    }

    if (fail) {
        printf("No solution!");
    } else if (residual < mat.front().size() - 1) {
        printf("No unique solution!");
    } else {
        for (int i = 0; i < mat.size(); i++) {
            if (i)
                printf(" ");
            printf("%.3f", mat[i].back());
        }
    }

    return 0;
}
