#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//Trie structure
struct node {
    int height;
    node* leaf[30];
    node* father;
    node* ancestors[30];
    node(char* ans, int height, node*& answer, node* father = nullptr) : height(height), father(father) {
        int p      = strlen(ans);
        int s      = ans[p - 1] - 'a';
        ans[p - 1] = '\0';
        for (int i = 0; i < 30; i++) {
            leaf[i]      = nullptr;
            ancestors[i] = nullptr;
        }
        ancestors[0] = father;
        for (int i = 1; ancestors[i - 1]->ancestors[i - 1] != nullptr; i++) {
            ancestors[i] = ancestors[i - 1]->ancestors[i - 1];
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
            leaf[i]      = nullptr;
            ancestors[i] = nullptr;
        }
        if (father != nullptr) {
            ancestors[0] = father;
            for (int i = 1; ancestors[i - 1]->ancestors[i - 1] != nullptr; i++) {
                ancestors[i] = ancestors[i - 1]->ancestors[i - 1];
            }
        } else {
            ancestors[0] = nullptr;
        }
    }
};
node* appendn(node*& root, char* anss, int height = 1) {
    int p       = strlen(anss);
    int s       = anss[p - 1] - 'a';
    anss[p - 1] = '\0';
    if (p == 1 && root->leaf[s] != nullptr) {
        return root->leaf[s];
    }
    if (root->leaf[s] != nullptr) {
        return appendn(root->leaf[s], anss, height + 1);
    } else {
        node* ans;
        if (p != 1)
            root->leaf[s] = new node(anss, height + 1, ans, root);
        else {
            root->leaf[s] = new node(height + 1, root);
            ans           = root->leaf[s];
        }
        return ans;
    }
}
node* root = new node();
node* LCA(node* n1, node* n2) {
    if (n1->height < n2->height) {
        node* tmp = n1;
        n1        = n2;
        n2        = tmp;
    }
    int p = n1->height - n2->height;
    for (int i = 0; p > 0; i++) {
        if (p & 1) {
            n1 = n1->ancestors[i];
        }
        p >>= 1;
    }
    if (n1 == n2) {
        return n1;
    }
    for (int i = 29; i >= 0; i--) {
        if (n1->ancestors[i] == nullptr)
            continue;
        if (n1->ancestors[i] != n2->ancestors[i]) {
            n1 = n1->ancestors[i];
            n2 = n2->ancestors[i];
        }
    }
    return n1->father;
}
node* db[100010] = {nullptr};
char gene[10005] = {};
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