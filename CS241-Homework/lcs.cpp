#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline int cmp(string& str1, string& str2, int x, int y) {
    if (str1.size() <= x || str2.size() <= y)
        return false;
    return str1[x] == str2[y];
}

void LCS(vector<vector<pair<int, int>>>& ve, string& str1, string& str2, int x,
         int y) {
    if (x == 0 || y == 0) {
        ve[x][y] = pair<int, int>(0, 0);
        return;
    }
    ve[x][y].second = cmp(str1, str2, x - 1, y - 1)
                          ? ve[x - 1][y - 1].second + 1
                          : max(ve[x][y - 1].second, ve[x - 1][y].second);
    ve[x][y].first  = cmp(str1, str2, x - 1, y - 1)
                          ? 1
                          : ((ve[x][y - 1].second == ve[x][y].second) << 1) |
                               ((ve[x - 1][y].second == ve[x][y].second) << 2);
    return;
}

set<string> traverse_back(vector<vector<pair<int, int>>>& ve, string str,
                          string& str1, string& str2, int x, int y) {
    if (x == 0 || y == 0)
        return set<string>{str};
    set<string> set0;
    if (ve[x][y].first & 0b001)
        for (auto t :
             traverse_back(ve, str1[x - 1] + str, str1, str2, x - 1, y - 1))
            set0.insert(t);
    if (ve[x][y].first & 0b010)
        for (auto t : traverse_back(ve, str, str1, str2, x, y - 1))
            set0.insert(t);
    if (ve[x][y].first & 0b100)
        for (auto t : traverse_back(ve, str, str1, str2, x - 1, y))
            set0.insert(t);
    return set0;
}

set<string> LCS(string X, string Y) {
    auto ve = vector<vector<pair<int, int>>>();
    for (int t = 0; t <= X.size(); t++) {
        ve.push_back(vector<pair<int, int>>());
        for (int v = 0; v <= Y.size(); v++)
            ve.back().push_back(pair<int, int>());
    }
    for (int t = 0; t <= X.size(); t++)
        for (int v = 0; v <= Y.size(); v++)
            LCS(ve, X, Y, t, v);
    if (ve[X.size()][Y.size()].second == 0) 
        return set<string>();
    return traverse_back(ve, "", X, Y, X.size(), Y.size());
}

int main() {
    string X, Y;
    cin >> X;
    cin >> Y;

    set<string> lcs = LCS(X, Y);

    // print set elements
    for (string str : lcs)
        cout << str << endl;

    return 0;
}