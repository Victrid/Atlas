#include <cstdio>
#include <iostream>
using namespace std;
int N;
struct node {
    int value;
    int index;
    bool isleaf;
    node* left;
    node* right;
    node& operator=(const node& rhs) {
        if (this == &rhs)
            return *this;
        value = rhs.value;
        index = rhs.index;
        left  = rhs.left;
        right = rhs.right;
        return *this;
    }
};
void swap(node& n1, node& n2) {
    node tmp = n1;
    n1       = n2;
    n2       = tmp;
    return;
}
node* strage[200000];
void siftup(int nodec) {
    if (nodec == 1 || nodec == 0)
        return;
    if (strage[nodec]->value < strage[nodec >> 1]->value) {
        swap(strage[nodec], strage[nodec >> 1]);
        siftup(nodec >> 1);
    }
    return;
}
void heapify(int nodec, int treesize) {
    if (nodec >= treesize)
        return;
    if (nodec << 1 <= treesize && strage[nodec]->value > strage[nodec << 1]->value) {
        swap(strage[nodec], strage[nodec << 1]);
        heapify(nodec << 1, treesize);
    }
    if ((nodec << 1 | 1) <= treesize && strage[nodec]->value > strage[nodec << 1 | 1]->value) {
        swap(strage[nodec], strage[nodec << 1 | 1]);
        heapify(nodec << 1 | 1, treesize);
    }
    return;
}
node* construct() {
    scanf("%d", &N);
    if (N == 0)
        return nullptr;
    for (int i = 1; i <= N; i++) {
        strage[i] = new node;
        scanf("%d", &(strage[i]->value));
        strage[i]->index  = i;
        strage[i]->left   = nullptr;
        strage[i]->right  = nullptr;
        strage[i]->isleaf = true;
    }
    for (int i = 2; i <= N; i++) {
        siftup(i);
    }
    int treestrt = N;
    while (treestrt != 1) {
        node* ptrf = strage[1];
        strage[1]  = strage[treestrt];
        treestrt--;
        heapify(1, treestrt);
        node* vs   = new node;
        vs->value  = ptrf->value + strage[1]->value;
        vs->left   = ptrf;
        vs->right  = strage[1];
        vs->isleaf = false;
        strage[1]  = vs;
        heapify(1, treestrt);
    }
    return strage[1];
}
long long answ = 0;
void traverse(node* root, int level) {
    if (root->isleaf) {
        answ += level * root->value;
        return;
    }
    if (root->left != nullptr)
        traverse(root->left, level + 1);
    if (root->right != nullptr)
        traverse(root->right, level + 1);
}
int main() {
    node* ans = construct();
    if (ans != nullptr)
        traverse(ans, 0);
    printf("%lld", answ);
    return 0;
}