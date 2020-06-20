#include <iostream>
using namespace std;
long long strage[400005];
int treesize;
void swap(long long& a1, long long& a2) {
    if (a1 != a2) {
        a1 ^= a2;
        a2 ^= a1;
        a1 ^= a2;
    }
    return;
};
void insert(long long i) {
    strage[++treesize] = i;
    int x              = treesize;
    while (x != 1) {
        if (strage[x] < strage[x >> 1]) {
            swap(strage[x], strage[x >> 1]);
            x >>= 1;
        } else
            break;
    }
    return;
}
long long pop() {
    swap(strage[1], strage[treesize]);
    treesize--;
    int i = 2;
    while (i <= treesize) {
        if ((i | 1) <= treesize && strage[i | 1] < strage[i])
            i |= 1;
        if (strage[i] < strage[i >> 1]) {
            swap(strage[i], strage[i >> 1]);
            i <<= 1;
        } else
            break;
    }
    return strage[treesize + 1];
}
int main() {
    int n, x, y;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        insert(x);
    }
    while (treesize > 1) {
        x = pop();
        y = pop();
        ans += x + y;
        insert(x + y);
    }
    printf("%lld", ans);
    return 0;
}