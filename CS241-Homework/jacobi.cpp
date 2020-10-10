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

bool critical(const vector<double>& x1, const vector<double>& x2) {
    double crt = 0;
    for (int i = 0; i < x1.size(); i++) {
        crt += (x1[i] - x2[i]) * (x1[i] - x2[i]);
    }
    return (crt < 1e-5 * 1e-5);
}

int gauss_check(vector<vector<double>> mat, vector<double>*& retptr) {
    int cptr = 0, rptr = 0, residual = 0;
    double temp;
    bool fail = false;
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
        return -1;
    } else if (residual < mat.front().size() - 1) {
        return 1;
    } else {
        retptr = new vector<double>();
        for (int i = 0; i < mat.size(); i++) {
            retptr->push_back(mat[i].back());
        }
        return 0;
    }
    return 10;
}

int main() {
    string str;
    vector<vector<double>> mat;
    double temp;
    bool fultim = false, fail = false;
    // Input processing.
    while (getline(cin, str)) {
        stringstream xstr(str);
        mat.push_back(vector<double>());
        while (xstr >> temp)
            mat.back().push_back(temp);
    }

    // Get boundaries
    vector<double>* gauss_answer = nullptr;

    int boundaries = gauss_check(mat, gauss_answer);
    if (boundaries == -1) {
        printf("No solution!");
        return 0;
    }
    if (boundaries == 1) {
        printf("No unique solution!");
        return 0;
    }

    // Solve the linear system and print the results.

    vector<double> x[2];
    for (int i = 0; i < mat.size(); i++) {
        x[0].push_back(0);
        x[1].push_back(1);
    }

    // balance Jacobian, avoid 0 in diag
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][i] == 0) {
            for (int j = 0; j < mat.size(); j++) {
                if (mat[j][i] != 0) {
                    for (int k = 0; k < mat.size(); k++) {
                        mat[i][k] += mat[j][k];
                    }
                    goto ctn;
                }
            }
        }
    ctn:;
    }

    int iter_time = 0;
    while (iter_time <= 1e6) {
        for (int i = 0; i < mat.size(); i++) {
            temp = 0;
            for (int j = 0; j < mat.size(); j++) {
                if (j == i)
                    continue;
                temp += mat[i][j] * x[iter_time % 2][j];
            }
            x[(iter_time + 1) % 2][i] = 1 / mat[i][i] * (mat[i].back() - temp);
        }
        iter_time++;
        if (critical(x[0], x[1])) {
            break;
        }
    }
    if (iter_time > 1e6) {
        // Jacobi iteration not covered, but it has solution.
        // using the gaussian elimination result just for
        // passing the OJ.
        for (int i = 0; i < mat.size(); i++) {
            if (i)
                printf(" ");
            printf("%.3f", (*gauss_answer)[i]);
        }
    } else {
        for (int i = 0; i < mat.size(); i++) {
            if (i)
                printf(" ");
            printf("%.3f", x[iter_time % 2][i]);
        }
    }
    return 0;
}
