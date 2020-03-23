#include <iostream>
using namespace std;
int main() {
    // a math problem?
    int m, n, k;
    cin >> m;
    bool* ans = new bool[m];
    for (int i = 0; i < m; i++) {
        cin >> n >> k;
        //赌王把一个环剪开成了绳子。
        //Juda把绳子剪成长度相等的两条绳子。
        //赌王怎么剪Juda就怎么剪。就获胜了。

        //一次一个的划，能不能剪出来要看奇偶。
        if (k == 1) {
            ans[i] = n % 2;
            continue;
        }
        //一把就直接把所有数都划掉
        ans[i] = k >= n;
    }
    for (int i = 0; i < m; i++) {
        if (i)
            cout << endl;
        cout << (ans[i] ? "5555" : "Yeah!");
    }
    return 0;
}
