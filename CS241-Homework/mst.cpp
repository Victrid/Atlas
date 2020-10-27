#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct edge {
    int A;
    int B;
    int Weight;
};

struct edge_compare {
    bool operator()(edge& a, edge& b) { return a.Weight > b.Weight; }
};

int mst_prim(vector<vector<int>>& matrix) {
    int total = 0;
    set<int> visited;
    priority_queue<edge, vector<edge>, edge_compare> q;
    visited.insert(0);
    for (int i = 0; i < matrix[0].size(); i++)
        if (visited.find(i) == visited.end() && matrix[0][i] != 0)
            q.push(edge{0, i, matrix[0][i]});
    while (!q.empty()) {
        edge st = q.top();
        q.pop();
        if (visited.find(st.A) != visited.end() &&
            visited.find(st.B) != visited.end())
            continue;
        int newpoint = visited.find(st.A) != visited.end() ? st.B : st.A;
        visited.insert(newpoint);
        total += st.Weight;
        for (int i = 0; i < matrix[newpoint].size(); i++)
            if (visited.find(i) == visited.end() && matrix[newpoint][i] != 0)
                q.push(edge{newpoint, i, matrix[newpoint][i]});
    }
    return total;
}

int main() {
    string str;
    vector<vector<int>> mat;
    int temp;
    while (getline(cin, str)) {
        stringstream xstr(str);
        mat.push_back(vector<int>());
        while (xstr >> temp)
            mat.back().push_back(temp);
    }
    cout << mst_prim(mat);
    return 0;
}