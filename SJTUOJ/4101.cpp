#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//Trie structure
struct node {
    int height;
    node* leaf[30];
    node* father;
    node(char* ans, int height, node*& answer, node* father = nullptr) : height(height), father(father) {
        int p      = strlen(ans);
        char s     = ans[p - 1] - 'a';
        ans[p - 1] = '\0';
        for (int i = 0; i < 30; i++) {
            leaf[i] = nullptr;
        }
        if (p != 1)
            leaf[s] = new node(ans, height + 1, answer, this);
        else {
            leaf[s] = new node(height + 1, this);
            answer  = leaf[s];
        }
    }
    node(int height = 1, node* father = nullptr) : height(height), father(father) {
        for (int i = 0; i < 30; i++) {
            leaf[i] = nullptr;
        }
    }
};
node* appendn(node*& root, char* anss, int height = 1) {
    int p       = strlen(anss);
    char s      = anss[p - 1] - 'a';
    anss[p - 1] = '\0';
    if (p == 1 and root->leaf[s] != nullptr) {
        return root->leaf[s];
    }
    if (root->leaf[s] != nullptr) {
        return appendn(root->leaf[s], anss, height + 1);
    } else {
        node* ans;
        root->leaf[s] = new node(anss, height + 1, ans, root);
        return ans;
    }
}
node* LCA(node* n1, node* n2) {
    if (n1->height < n2->height) {
        node* tmp = n1;
        n1        = n2;
        n2        = tmp;
    }
    int p = n1->height - n2->height;
    while (p--) {
        n1 = n1->father;
    }
    while (n1 != n2) {
        n1 = n1->father;
        n2 = n2->father;
    }
    return n1;
}
node* root       = new node();
node* db[100010] = {nullptr};
char gene[10005]={};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", gene);
        db[i] = appendn(root, gene);
    }
    //Brute-force mlgn
    int proc, op;
    while (m--) {
        scanf("%d", &proc);
        if (proc == 1) {
            scanf("%s", gene);
            db[++n] = appendn(root, gene);
        } else {
            scanf("%d", &proc);
            proc--;
            scanf("%d", &op);
            node* publici = db[op];
            while (proc--) {
                scanf("%d", &op);
                if (publici != root) {
                    publici = LCA(publici, db[op]);
                }
            }
            printf("%d\n", publici->height - 1);
        }
    }
    return 0;
}