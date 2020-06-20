#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int father[100005] = {0};
bool del[100005]   = {false};

int anc(int x) { return father[x] == x ? x : father[x] = anc(father[x]); }

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        father[i] = i;
    int op, x, y;
    while (m--) {
        scanf("%d", &op);
        switch (op) {
        case 1:
            scanf("%d%d", &x, &y);
            father[anc(x)] = anc(y);
            break;
        case 2:
            scanf("%d%d", &x, &y);
            if (del[x] || del[y])
                printf("NO\n");
            else
                printf(anc(x) == anc(y) ? "YES\n" : "NO\n");
            break;
        case 3:
            scanf("%d", &x);
            del[x] = true;
            break;
        }
    }
    return 0;
}