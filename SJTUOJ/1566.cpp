#include <cstdio>
#include <iostream>
using namespace std;

struct edge {
    int v;
    int w;
    int weight;
    
    edge& operator=(const edge& rhs) {
        v      = rhs.v;
        w      = rhs.w;
        weight = rhs.weight;
        return *this;
    }
    bool operator<(const edge& rhs) const { return weight < rhs.weight; }
};

edge strage[200];
int treesize;
void swap(edge& a1, edge& a2) {
    edge temp = a1;
    a1        = a2;
    a2        = temp;
    return;
};
void insert(edge i) {
    strage[++treesize] = i;
    int x              = treesize;
    while (x != 1) {
        if (strage[x] < strage[x >> 1]) {
            swap(strage[x], strage[x >> 1]);
            x >>= 1;
        } else
            break;
    }
    return;
}
edge pop() {
    swap(strage[1], strage[treesize]);
    treesize--;
    int i = 2;
    while (i <= treesize) {
        if ((i | 1) <= treesize && strage[i | 1] < strage[i])
            i |= 1;
        if (strage[i] < strage[i >> 1]) {
            swap(strage[i], strage[i >> 1]);
            i <<= 1;
        } else
            break;
    }
    return strage[treesize + 1];
}

int weight[30][30] = {0};
bool visited[30]   = {false};

int total;

void visit(int v) {
    if (visited[v])
        return;
    visited[v] = true;
    for (int w = 0; w < total; ++w) {
        if (w == v || weight[v][w] == 0)
            continue;
        insert(edge{v, w, weight[v][w]});
    }
}

int main() {
    char ch1, ch2;
    int a, b, ans = 0;
    scanf("%d", &total);
    for (int i = total - 1; i; i--) {
        scanf(" %c %d", &ch1, &a);
        while (a--) {
            scanf(" %c %d", &ch2, &b);
            weight[ch1 - 'A'][ch2 - 'A'] = weight[ch2 - 'A'][ch1 - 'A'] = b;
        }
    }
    visit(0);
    while (treesize) {
        edge e = pop();
        if (visited[e.v] && visited[e.w])
            continue;
        ans += e.weight;
        visit(e.v);
        visit(e.w);
    }
    printf("%d", ans);
    return 0;
}