#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int npl;
    int value;
};
void npl(node& ps) {
    if (ps.left == nullptr || ps.right == nullptr) {
        ps.npl = 0;
        return;
    } else {
        ps.npl = min(ps.left->npl, ps.right->npl) + 1;
        return;
    }
}
node*& merge(node*& lhs, node*& rhs) {
    if (rhs == nullptr)
        return lhs;
    if (lhs == nullptr) {
        lhs = rhs;
        rhs = nullptr;
        return lhs;
    }
    if (lhs->value > rhs->value) {
        merge(rhs, lhs);
        lhs = rhs;
        rhs = nullptr;
        return lhs;
    }
    lhs->right = merge(lhs->right, rhs);
    if (lhs->left == nullptr || lhs->left->npl <= lhs->right->npl) {
        node* tmp  = lhs->left;
        lhs->left  = lhs->right;
        lhs->right = tmp;
    }
    npl(*lhs);
    rhs = nullptr;
    return lhs;
}
node* insert(node*& root, int val) {
    node* n = new node{nullptr, nullptr, 0, val};
    return merge(root, n);
}
int pop(node*& root) {
    //I am blind
    if (root == nullptr)
        return -1;
    int ps      = root->value;
    node* roots = root;
    root        = merge(root->left, root->right);
    delete roots;
    return ps;
}
node* ns[300010];
int main() {
    int n, m, cha, prc, pra, prb;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cha);
        ns[i] = new node{nullptr, nullptr, 0, cha};
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &prc);
        switch (prc) {
        case 0:
            scanf("%d %d", &pra, &prb);
            merge(ns[pra], ns[prb]);
            break;
        case 1:
            scanf("%d", &pra);
            printf("%d\n", pop(ns[pra]));
            break;
        case 2:
            scanf("%d %d", &pra, &prb);
            insert(ns[pra], prb);
            break;
        }
    }
    return 0;
}