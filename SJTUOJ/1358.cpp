//?4189?
#include <cstdio>
#include <iostream>
using namespace std;
struct ln {
    int pos;
    ln* next;
};

ln lis[1000005];
int sz[1000005]     = {0};
int parent[1000005] = {0};

int DFS(int pos) {
    sz[pos] = 1;
    ln* nx  = &lis[pos];
    while (nx->next != NULL) {
        nx = nx->next;
        if (parent[pos] != nx->pos) {
            parent[nx->pos] = pos;
            sz[pos] += DFS(nx->pos);
        }
    }
    return sz[pos];
}

int main() {
    int N, p, q;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &p, &q);
        lis[p].pos = p;
        lis[q].pos = q;
        ln* pp     = &lis[p];
        while (pp->next != nullptr) {
            pp = pp->next;
        }
        pp->next = new ln{q, nullptr};
        ln* qp   = &lis[q];
        while (qp->next != nullptr) {
            qp = qp->next;
        }
        qp->next = new ln{p, nullptr};
    }
    DFS(1);
    //Only one needed. I'm blind.
    for (int i = 1; i <= N; ++i) {
        if (N - sz[i] > N / 2) {
            continue;
        }
        bool flag = true;
        ln* nx    = &lis[i];
        while (nx->next != NULL) {
            nx = nx->next;
            if (parent[i] != nx->pos) {
                if (sz[nx->pos] > N / 2) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            printf("%d ", i);
        }
    }
    return 0;
}