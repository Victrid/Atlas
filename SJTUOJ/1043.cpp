#include <cstdio>
#include <iostream>
using namespace std;
struct tree {
    tree* left;
    tree* right;
    bool valid;
    enum { none,
           one,
           both } occupied;
    tree(int n) : left(nullptr), right(nullptr), valid(true), occupied(none){};
    tree() : left(nullptr), right(nullptr), valid(false), occupied(none){};
};
tree nodes[1000001] = {};
//! queue must be large enough to handle a full tree
tree* queuet[4000003] = {nullptr};
tree** queueex;
tree** queueend;
void clearqueue() {
    queueex  = queuet;
    queueend = queuet + 1;
}
void enqueue(tree* tptr) {
    *queueend = tptr;
    queueend++;
}
tree* dequeue() {
    if (queueex + 1 == queueend)
        return nullptr;
    else
        queueex++;
    return *queueex;
}
int main() {
    int N;
    scanf("%d", &N);
    int proc;
    nodes[0].valid = true;
    for (int i = 1; i < N; i++) {
        nodes[i].valid = true;
        scanf("%d", &proc);
        switch (nodes[proc].occupied) {
        case tree::none:
            nodes[proc].occupied = tree::one;
            nodes[proc].left     = nodes + i;
            break;
        case tree::one:
            nodes[proc].occupied = tree::both;
            nodes[proc].right    = nodes + i;
            break;
        case tree::both:
            cout << "false";
            return 0;
            break;
        }
    }
    clearqueue();
    enqueue(nodes);
    tree* proce;
    int tcount = 0;
    proce      = dequeue();
    while (proce != nullptr) {
        if (!proce->valid)
            continue;
        tcount++;
        proce->valid = false;
        enqueue(proce->left);
        enqueue(proce->right);
        proce = dequeue();
    }
    if (tcount == N)
        cout << "true";
    else
        cout << "false";
    return 0;
}