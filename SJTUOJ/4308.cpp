#include <cstdio>
#include <iostream>
using namespace std;
struct node;
struct son {
    son* next;
    node* value;
    son(son* next = nullptr, node* value = nullptr) : next(next), value(value){};
};
struct node {
    int height;
    son* sons;
    node() : height(0),
             sons(nullptr) {}
};
node tree[100003];
node* oila[200003];
int st[200005][20];
int first[100003] = {0};
inline int lg(int n) { return n ? lg(n / 2) + 1 : -1; }
int dfs(node**& oilaptr, node* root, int height) {
    *oilaptr = root;
    if (!first[root - tree]) {
        first[root - tree] = oilaptr - oila;
    }
    oilaptr++;
    root->height = height;
    son* sss     = root->sons;
    while (sss != nullptr) {
        dfs(oilaptr, sss->value, height + 1);
        *oilaptr = root;
        oilaptr++;
        sss = sss->next;
    }
    return 0;
}

int main() {
    int n, m, g;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &g);
        tree[g].sons = new son(tree[g].sons, tree + i);
    }
    node* root     = tree + 1;
    node** oilaptr = oila + 1;
    //obey to 1-base
    dfs(oilaptr, root, 1);
    for (int i = 1; i <= oilaptr - oila - 1; i++) {
        st[i][0] = i;
    }
    for (int j = 1; j <= lg(oilaptr - oila - 1); j++) {
        for (int i = 1; i + (1 << j) <= oilaptr - oila; i++) {
            st[i][j] = oila[st[i][j - 1]]->height < oila[st[i + (1 << (j - 1))][j - 1]]->height ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        }
    }
    int pos, rr, ll, pent;
    while (m--) {
        scanf("%d%d", &pos, &ll);
        ll = first[ll];
        rr = ll;
        pos--;
        while (pos--) {
            scanf("%d", &pent);
            if (first[pent] < ll) {
                ll = first[pent];
            } else if (first[pent] > rr) {
                rr = first[pent];
            }
        }
        if (oila[st[ll][lg(rr - ll + 1)]]->height < oila[st[rr + 1 - (1 << lg(rr - ll + 1))][lg(rr - ll + 1)]]->height) {
            printf("%ld\n", oila[st[ll][lg(rr - ll + 1)]] - tree);
        } else {
            printf("%ld\n", oila[st[rr + 1 - (1 << lg(rr - ll + 1))][lg(rr - ll + 1)]] - tree);
        }
    }
    return 0;
}