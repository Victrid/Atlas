#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Let's see, it's the same polynomial
class Lagrange {
public:
    Lagrange(const vector<double>& x, const vector<double>& y) : X(x), Y(y) {
        if (X.size() != Y.size())
            throw exception();
    }

    double calc(double x) {
        double ans = 0;
        double xvr = 1, pvr = 1;
        for (auto t = 0; t != X.size(); t++) {
            xvr = 1;
            pvr = 1;
            for (auto v = X.begin(); v != X.end(); v++) {
                if (X.begin() + t != v) {
                    xvr *= (X[t] - *v);
                    pvr *= (x - *v);
                }
            }
            if (xvr == 0)
                continue;
            ans += pvr / xvr * Y[t];
        }
        return ans;
    }

private:
    const vector<double>& X;
    const vector<double>& Y;
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
    Lagrange lg(X, Y);

    // interp_x is the point to be interpolated.
    double interp_x;
    cin >> interp_x;

    printf("%.3f", lg.calc(interp_x));

    return 0;
}
