#include <iostream>
using namespace std;
struct tree {
    tree* left;
    tree* right;
    int weight;
    bool isroot;
    tree() : left(nullptr), right(nullptr), weight(0), isroot(true){};
};
bool qxblf = false;
void qxbl(tree* root) {
    if (qxblf)
        printf(" ");
    qxblf = true;
    printf("%d", root->weight);
    if (root->left != nullptr)
        qxbl(root->left);
    if (root->right != nullptr)
        qxbl(root->right);
    return;
}
bool hxblf = false;
void hxbl(tree* root) {
    if (root->left != nullptr)
        hxbl(root->left);
    if (root->right != nullptr)
        hxbl(root->right);
    if (hxblf)
        printf(" ");
    hxblf = true;
    printf("%d", root->weight);
    return;
}
//queue and stack
//content: tree*, default empty: nullptr
tree* datastorage[4000003] = {nullptr};
tree** frontptr;
tree** endptr;
void clearqueue() {
    frontptr = datastorage;
    endptr   = datastorage + 1;
}
void clearstack() {
    endptr = datastorage;
}
void enqueue(tree* cr) {
    *endptr = cr;
    endptr++;
}
bool qempty() {
    return frontptr + 1 == endptr;
}
void enstack(tree* cr) {
    *endptr = cr;
    endptr++;
}
tree* destack() {
    if (endptr == datastorage)
        return nullptr;
    else
        endptr--;
    return *endptr;
}
tree* dequeue() {
    if (frontptr + 1 == endptr)
        return nullptr;
    else
        frontptr++;
    return *frontptr;
}
void ccbl(tree* root) {
    clearqueue();
    enqueue(root);
    bool cflg = false;
    while (!qempty()) {
        tree* proc = dequeue();
        if (proc->left != nullptr)
            enqueue(proc->left);
        if (proc->right != nullptr)
            enqueue(proc->right);
        if (cflg)
            printf(" ");
        cflg = true;
        printf("%d", proc->weight);
    }
    return;
}
tree sqt[100005] = {};
int main() {
    int n, l, r, vl, root;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &l, &r, &vl);
        if (l != 0) {
            sqt[i].left         = sqt + l;
            sqt[i].left->isroot = false;
        }
        if (r != 0) {
            sqt[i].right         = sqt + r;
            sqt[i].right->isroot = false;
        }
        sqt[i].weight = vl;
    }
    for (int i = 1; i <= n; i++)
        if (sqt[i].isroot) {
            root = i;
            break;
        }
    qxbl(sqt + root);
    printf("\n");
    hxbl(sqt + root);
    printf("\n");
    ccbl(sqt + root);
    printf("\n");
    return 0;
}