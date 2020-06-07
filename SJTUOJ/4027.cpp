#include <cstdio>
#include <iostream>
using namespace std;

int dseq[100010];
int qseq[100010];
int dp[100010] = {0};

int bifind(int left, int right, int val) {
    int ans = right;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (val > dp[mid]) {
            left = mid + 1;
        } else if (val <= dp[mid]) {
            ans   = mid;
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, pc;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pc);
        dseq[pc] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pc);
        qseq[dseq[pc]] = i;
    }
    //now find the longest increase sequence
    int len = 1, lhs, rhs, pos;
    dp[1]   = qseq[1];
    for (int i = 2; i <= n; i++) {
        if (qseq[i] > dp[len]) {
            dp[++len] = qseq[i];
            continue;
        }
        dp[bifind(1, len, qseq[i])] = qseq[i];
    }
    printf("%d", len);
    return 0;
}