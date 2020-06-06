#include <cstdio>
#include <cstring>
#include <iostream>

//Testing
#include <queue>
#include <stack>
#include <vector>

using namespace std;
struct son;
struct node {
    int num;
    son* sons;
    node(int num) : num(num), sons(nullptr) {}
};
struct lo {
    bool operator()(const node* x, const node* y) const {
        return x->num > y->num;
    }
};
struct son {
    son* next;
    node* val;
};
stack<node*> s;

priority_queue<node*, vector<node*>, lo> q;
node* root;
void connect(node* n1, node* n2) {
    n1->sons = new son{n1->sons, n2};
    n2->sons = new son{n2->sons, n1};
    return;
}
bool isleaf(node* n1) {
    return n1->sons == nullptr && n1->sons->next == nullptr;
}
void disconnect(node* n1) {
    son* s2 = n1->sons->val->sons;
    if (s2->next == nullptr) {
        n1->sons->val->sons = nullptr;
    } else {
        while (s2->next->val != n1)
            s2 = s2->next;
        s2->next = s2->next->next;
    }
    return;
}

int main() {
    char ch;
    ch = getchar();

    bool rootfd = false;
    while (ch != '\n' && ch != EOF) {
        while (ch == ' ') {
            ch = getchar();
        }
        if (ch == '(') {
            int num = 0;
            ch      = getchar();
            while (isdigit(ch)) {
                num = num / 10 + ch - '0';
                ch  = getchar();
            }
            if (!rootfd) {
                root = new node(num);
                s.push(root);
                rootfd = true;
            } else {
                s.push(new node(num));
            }
        } else if (ch == ')') {
            node* p = s.top();
            s.pop();
            if (!s.empty()) {
                if (p->sons == nullptr)
                    q.push(p);
                connect(p, s.top());
            }
            ch = getchar();
        }
    }
    while (!q.empty()) {
        auto l = q.top();
        q.pop();
        if (l->sons == nullptr)
            break;
        auto father = l->sons->val;
        printf("%d ", father->num);
        if (l == root) {
            root = father;
        }
        disconnect(l);
        if (isleaf(father)) {
            q.push(father);
        }
    }
    return 0;
}