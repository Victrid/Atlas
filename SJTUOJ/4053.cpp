#include <cstring>
#include <iostream>
using namespace std;
//Is the cout's problem?
//下次再不printf我直播吃屎
bool sum_is_prime[17][17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
                             0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0,
                             0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                             0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                             0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0,
                             0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
                             0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
                             0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0,
                             0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
                             0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,
                             0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                             0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                             0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                             0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
                             0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};

bool visited[17] = {0};
int storage[17]  = {0};
bool gotcha      = false;
int dfs(int num, int depth, int total) {
    depth += 1;
    visited[num]   = true;
    storage[depth] = num;
    if (depth == total) {
        if (sum_is_prime[1][num]) {
            for (int i = 1; i <= depth; i++) {
                printf("%d ", storage[i]);
            }
            printf("\n");
            gotcha = true;
        } else {
            visited[num] = false;
            return 0;
        }
    }
    for (int i = 2 + (num & 1) ^ 1; i <= total; i += 2)
        if (sum_is_prime[num][i] && (!visited[i]))
            dfs(i, depth, total);
    visited[num] = false;
    return 0;
}
int main() {
    int total;
    cin >> total;
    if (total & 1) {
        cout << "None" << endl;
        return 0;
    }
    dfs(1, 0, total);
    if (!gotcha)
        cout << "None" << endl;
    return 0;
}