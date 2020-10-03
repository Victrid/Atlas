#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// You can add additional standard libraries if necessary.
// Implement the Newton interpolation!
class Newton {
public:
    Newton(const vector<double>& x, const vector<double>& y) : X(x), Y(y) {
        t = new double*[Y.size()];
        for (int i = 0; i < Y.size(); i++) {
            t[i]    = new double[Y.size()];
            t[0][i] = Y[i];
        }
        for (int i = 1; i < Y.size(); i++) {
            for (int j = i; j < Y.size(); j++) {
                t[i][j] = (t[i - 1][j] - t[i - 1][j - 1]) / (X[j] - X[j - i]);
            }
        }
    }
    double calc(double x) {
        double x0  = 1;
        double ans = 0;
        for (int i = 0; i < Y.size(); i++) {
            ans += x0 * t[i][i];
            x0 *= (x - X[i]);
        }
        return ans;
    }

    ~Newton() {
        for (int i = 0; i < Y.size(); i++) {
            delete[] t[i];
        }
        delete[] t;
    }

private:
    const vector<double>& X;
    const vector<double>& Y;
    double** t;
};

// Test your implementation.
int main(int argc, const char* argv[]) {
    //  Input preprocessing.
    string str;
    getline(cin, str);
    stringstream xstr(str);
    getline(cin, str);
    stringstream ystr(str);

    // X and Y are two vectors of equal length to be traversed.
    vector<double> X, Y;
    double a;
    while (xstr >> a)
        X.push_back(a);
    while (ystr >> a)
        Y.push_back(a);
    Newton nt(X, Y);

    // interp_x is the point to be interpolated.
    double interp_x;
    cin >> interp_x;

    // Do Newton interpolation for interp_x using X and Y, and print your
    // results Note: The result retains three decimal places (rounded)!
    printf("%.3f", nt.calc(interp_x));
    // End
    return 0;
}
