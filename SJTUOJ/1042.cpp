#include <cstdio>
#include <iostream>
using namespace std;
int N;
struct node {
    int son     = 0;
    int brat    = 0;
    bool isroot = true;
};
node treestr[12350];
int construct_tree() {
    int P = N, a, b, c;
    while (P--) {
        scanf("%d%d%d", &a, &b, &c);
        if (b != 0) {
            treestr[a].son    = b;
            treestr[b].isroot = false;
        }
        if (c != 0) {
            treestr[a].brat   = c;
            treestr[a].isroot = false;
            treestr[c].isroot = false;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (treestr[i].isroot)
            return i;
    }
    return 0;
}
void pretrav(int root) {
    printf("%d ", root);
    if (treestr[root].son != 0) {
        pretrav(treestr[root].son);
    }
    if (treestr[root].brat != 0) {
        pretrav(treestr[root].brat);
    }
    return;
}
void postrav(int root) {
    if (treestr[root].son != 0) {
        postrav(treestr[root].son);
    }
    printf("%d ", root);
    if (treestr[root].brat != 0) {
        postrav(treestr[root].brat);
    }
    return;
}
int queuet[12350] = {};
int* queueex;
int* queueend;
void clearqueue() {
    queueex  = queuet;
    queueend = queuet + 1;
}
void enqueue(int tptr) {
    *queueend = tptr;
    queueend++;
}
int dequeue() {
    if (queueex + 1 == queueend)
        return 0;
    else
        queueex++;
    return *queueex;
}
bool empty() {
    return (queueex + 1 == queueend);
}
void lvltrav(int root) {
    clearqueue();
    enqueue(root);
    while (!empty()) {
        int a = dequeue();
        while (a) {
            printf("%d ", a);
            if (treestr[a].son)
                enqueue(treestr[a].son);
            a = treestr[a].brat;
        }
    }
    return;
}
int main() {
    scanf("%d", &N);
    int root = construct_tree();
    pretrav(root);
    putchar('\n');
    postrav(root);
    putchar('\n');
    lvltrav(root);
    putchar('\n');
    return 0;
}