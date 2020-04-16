#include <cstdio>
#include <iostream>
using namespace std;

struct tree {
    tree* left;
    tree* brat;
    int weight;
    bool isroot;
    tree() : left(nullptr), brat(nullptr), weight(0), isroot(true){};
};

tree seq[1000002] = {};

//pretrav
bool pretrav_f = false;
void pretrav(tree* root) {
    if (pretrav_f)
        printf(" ");
    pretrav_f = true;
    printf("%d", root->weight);
    if (root->left != nullptr)
        pretrav(root->left);
    if (root->brat != nullptr)
        pretrav(root->brat);
    return;
}

//posttrav
bool posttrav_f = false;
void posttrav(tree* root) {
    if (root->left != nullptr)
        posttrav(root->left);
    if (posttrav_f)
        printf(" ");
    posttrav_f = true;
    printf("%d", root->weight);
    if (root->brat != nullptr)
        posttrav(root->brat);
    return;
}

//bfstrav
tree* datastorage[1000003] = {nullptr};
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
bool bfstrav_f = false;
void bfstrav(tree* root) {
    clearqueue();
    enqueue(root);
    while (!qempty()) {
        tree* rt = dequeue();
        while (rt != nullptr) {
            if (bfstrav_f)
                printf(" ");
            bfstrav_f = true;
            printf("%d", rt->weight);
            if (rt->left != nullptr)
                enqueue(rt->left);
            rt = rt->brat;
        }
    }
    return;
}
int main() {
    int t, l, b, vl, root;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &l, &b, &vl);
        if (l != 0) {
            seq[i].left         = seq + l;
            seq[i].left->isroot = false;
        }
        if (b != 0) {
            seq[i].brat         = seq + b;
            seq[i].brat->isroot = false;
        }
        seq[i].weight = vl;
    }
    for (int i = 1; i <= t; i++)
        if (seq[i].isroot) {
            root = i;
            break;
        }
    pretrav(seq + root);
    printf("\n");
    posttrav(seq + root);
    printf("\n");
    bfstrav(seq + root);
    printf("\n");

    return 0;
}