#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct son;
struct node {
    int num;
    son* sons;
    int soncount;
    node(int num) : num(num), sons(nullptr), soncount(0) {}
};
struct son {
    son* next;
    node* val;
};
class stacke {
public:
    node* stk[100005];
    node** stkptr;
    stacke() : stkptr(stk){};
    void push(node* n) {
        *stkptr = n;
        stkptr++;
    }
    node* top() {
        return *(stkptr - 1);
    }
    void pop() {
        stkptr--;
    }
    bool empty() {
        return stkptr == stk;
    }
};

stacke s;

class heap {
public:
    node* heap[100005];
    int heapsize;
    void swap(int a, int b) {
        node* tmp = heap[a];
        heap[a]   = heap[b];
        heap[b]   = tmp;
    }
    void siftup() {
        int i = heapsize;
        while (i != 1) {
            if (heap[i]->num < heap[i >> 1]->num) {
                swap(i, i >> 1);
                i >>= 1;
            } else
                break;
        }
    }
    void siftdown() {
        int i = 2;
        while (i <= heapsize) {
            if (i + 1 <= heapsize && heap[i + 1]->num < heap[i]->num)
                ++i;
            if (heap[i >> 1]->num > heap[i]->num) {
                swap(i, i >> 1);
                i *= 2;
            } else
                break;
        }
    }
    node* top() {
        return heap[1];
    }
    void pop() {
        swap(1, heapsize);
        --heapsize;
        siftdown();
    }
    void push(node* x) {
        heap[++heapsize] = x;
        siftup();
    }
    bool empty() {
        return !heapsize;
    }
};

heap q;
node* root;
void connect(node* n1, node* n2) {
    n1->sons = new son{n1->sons, n2};
    n1->soncount++;
    n2->sons = new son{n2->sons, n1};
    n2->soncount++;
    return;
}
bool isleaf(node* n1) {
    return n1 != root && n1->soncount == 1;
}
void disconnect(node* n1) {
    son* s2 = n1->sons->val->sons;
    if (n1->sons->val->soncount == 1) {
        n1->sons->val->sons = nullptr;
        n1->sons->val->soncount--;
    } else {
        if (s2->val == n1) {
            n1->sons = s2->next;
            n1->sons->val->soncount--;
            return;
        }
        while (s2->next->val != n1)
            s2 = s2->next;
        s2->next = s2->next->next;
        n1->sons->val->soncount--;
    }
    return;
}

int main() {
    char ch;
    ch          = getchar();
    int n       = 0;
    bool rootfd = false;
    while (ch != '\n' && ch != EOF) {
        while (ch == ' ') {
            ch = getchar();
        }
        if (ch == '(') {
            int num = 0;
            ch      = getchar();
            while (isdigit(ch)) {
                num = num * 10 + ch - '0';
                ch  = getchar();
            }
            if (!rootfd) {
                root = new node(num);
                s.push(root);
                rootfd = true;
                n++;
            } else {
                s.push(new node(num));
                n++;
            }
        } else if (ch == ')') {
            node* p = s.top();
            s.pop();
            if (!s.empty()) {
                if (p->sons == nullptr)
                    q.push(p);
                connect(p, s.top());
                ch = getchar();
            } else {
                break;
            }
        }
    }
    int t = 0;
    if (n == 1)
        return 0;
    while (!q.empty()) {
        auto l = q.top();
        q.pop();
        t++;
        if (l->sons == nullptr)
            break;
        if (t == n - 1)
            break;
        auto father = l->sons->val;
        printf("%d ", father->num);
        disconnect(l);
        if (isleaf(father)) {
            q.push(father);
        }
    }
    if (n)
        printf("%d ", max(root->num, root->sons->val->num));
    return 0;
}