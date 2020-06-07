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
//size!
node tree[50000];
node* oila[100000];
int st[100000][30];
int first[50000] = {0};
inline int lg(int n) { return n ? lg(n / 2) + 1 : -1; }
int dfs(node**& oilaptr, node* root, int height) {
    if (first[root - tree])
        return 0;
    first[root - tree] = oilaptr - oila;
    *oilaptr           = root;
    oilaptr++;
    root->height = height;
    son* sss     = root->sons;
    while (sss != nullptr) {
        if (dfs(oilaptr, sss->value, height + 1)) {
            *oilaptr = root;
            oilaptr++;
        }
        sss = sss->next;
    }
    return 1;
}

int main() {
    int n, m, g, r;
    scanf("%d", &n);
    node* root;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &g, &r);
        if (r == -1 || g == -1) {
            root = r == -1 ? tree + g : tree + r;
            continue;
        }
        tree[g].sons = new son(tree[g].sons, tree + r);
        tree[r].sons = new son(tree[r].sons, tree + g);
    }
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
    scanf("%d", &m);
    int pos, rr, ll, pent;
    while (m--) {
        scanf("%d%d", &ll, &rr);
        ll         = first[ll];
        rr         = first[rr];
        bool swapf = false;
        if (ll > rr) {
            ll ^= rr;
            rr ^= ll;
            ll ^= rr;
            swapf = true;
        }
        if (oila[st[ll][lg(rr - ll + 1)]]->height < oila[st[rr + 1 - (1 << lg(rr - ll + 1))][lg(rr - ll + 1)]]->height) {
            if (first[oila[st[ll][lg(rr - ll + 1)]] - tree] == ll)
                printf(swapf ? "2\n" : "1\n");
            else if (first[oila[st[ll][lg(rr - ll + 1)]] - tree] == rr)
                printf(swapf ? "1\n" : "2\n");
            else
                printf("0\n");
        } else {
            if (first[oila[st[rr + 1 - (1 << lg(rr - ll + 1))][lg(rr - ll + 1)]] - tree] == ll)
                printf(swapf ? "2\n" : "1\n");
            else if (first[oila[st[rr + 1 - (1 << lg(rr - ll + 1))][lg(rr - ll + 1)]] - tree] == rr)
                printf(swapf ? "1\n" : "2\n");
            else
                printf("0\n");
        }
    }
    return 0;
}