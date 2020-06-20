#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int cinbox[500010],
    cbox[500010],
    father[500010] = {0};

template <class T>
class AVL_mset {
    //   allow duplicate avl
public:
    struct node {
        T data;
        node* left;
        node* right;
        int size;
        node(const T& other, node* l, node* r) : data(other), left(l), right(r), size(1) {}
    };
    AVL_mset() : root(nullptr) {}
    bool find(const T& a) const { return find(a, root); }
    void insert(const T& a) { insert(a, root); }
    void remove(const T& a) { remove(a, root); }
    T& findi(int i) { return findi(i, root); }
    node* root;
    void insert(const T& a, node*& t) {
        if (t == 0) {
            t = new node(a, 0, 0);
        } else if (a > t->data) {
            insert(a, t->left);
            if (size(t->left) - size(t->right) == 2) {
                if (a > t->left->data)
                    LL(t);
                else
                    LR(t);
            }
            t->size = size(t->left) + size(t->right) + 1;
        } else {
            insert(a, t->right);
            if (size(t->right) - size(t->left) == 2) {
                if (a <= t->right->data)
                    RR(t);
                else
                    RL(t);
            }
            t->size = size(t->left) + size(t->right) + 1;
        }
    }
    void remove(const T& a, node*& t) {
        if (t == nullptr)
            return;
        if (a > t->data) {
            remove(a, t->left);
            if (size(t->right) - size(t->left) == 2) {
                node* r = t->right;
                if (size(r->left) > size(r->right))
                    RL(t);
                else
                    RR(t);
            }
            t->size = size(t->left) + size(t->right) + 1;
        } else if (a < t->data) {
            remove(a, t->right);
            if (size(t->left) - size(t->right) == 2) {
                node* r = t->left;
                if (size(r->right) > size(r->left))
                    LR(t);
                else
                    LL(t);
            }
            t->size = size(t->left) + size(t->right) + 1;
        } else if (t->left != 0 && t->right != 0) {
            if (size(t->left) <= size(t->right)) {
                node* tmp = t->right;
                while (tmp->left != 0)
                    tmp = tmp->left;
                t->data = tmp->data;
                remove(t->data, t->right);
                t->size = size(t->left) + size(t->right) + 1;
            } else {
                node* tmp = t->left;
                while (tmp->right != 0)
                    tmp = tmp->right;
                t->data = tmp->data;
                remove(t->data, t->left);
                t->size = size(t->left) + size(t->right) + 1;
            }
        } else {
            node* orig = t;
            t          = (t->left != nullptr) ? t->left : t->right;
            delete orig;
        }
    }
    bool find(const T& a, node* t) const {
        if (t == nullptr)
            return false;
        if (a > t->data)
            return find(a, t->left);
        if (a < t->data)
            return find(a, t->right);
        return true;
    }
    T& findi(int i, node*& t) {
        int rs = size(t->left);
        if (rs == i - 1)
            return t->data;
        if (rs >= i)
            return findi(i, t->left);
        else
            return findi(i - rs - 1, t->right);
    }
    int size(node* t) { return t == nullptr ? 0 : t->size; }
    void LL(node*& t) {
        node* t1  = t->left;
        t->left   = t1->right;
        t1->right = t;
        t->size   = size(t->left) + size(t->right) + 1;
        t1->size  = size(t1->left) + size(t) + 1;
        t         = t1;
    }
    void RR(node*& t) {
        node* t1 = t->right;
        t->right = t1->left;
        t1->left = t;
        t->size  = size(t->left) + size(t->right) + 1;
        t1->size = size(t1->right) + size(t) + 1;
        t        = t1;
    }
    void LR(node*& t) {
        RR(t->left);
        LL(t);
    }
    void RL(node*& t) {
        LL(t->right);
        RR(t);
    }
};

AVL_mset<int> mset;

int main() {
    int mbox, N, M, a, b, op;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        cinbox[i] = 1;
        mset.insert(1);
        cbox[i] = i;
    }
    mbox = N;
    for (int i = 1; i <= M; i++) {
        scanf("\n%c", &op);
        switch (op) {
        case 'C':
            scanf("%d%d", &a, &b);
            while (father[cbox[a]] != 0)
                cbox[a] = father[cbox[a]];
            while (father[cbox[b]] != 0)
                cbox[b] = father[cbox[b]];
            if (cbox[a] == cbox[b] || cinbox[cbox[a]] == 0 || cinbox[cbox[b]] == 0)
                break;
            mset.remove(cinbox[cbox[a]]);
            mset.remove(cinbox[cbox[b]]);
            cinbox[cbox[a]] += cinbox[cbox[b]];
            cinbox[cbox[b]] = 0;
            mset.insert(cinbox[cbox[a]]);
            father[cbox[b]] = cbox[a];
            mbox--;
            break;
        case 'D':
            scanf("%d", &a);
            while (father[cbox[a]] != 0)
                cbox[a] = father[cbox[a]];
            if (cinbox[cbox[a]] == 0)
                break;
            mset.remove(cinbox[cbox[a]]);
            cinbox[cbox[a]] = 0;
            mbox--;
            break;
        case 'Q':
            scanf("%d", &a);
            printf("%d\n", a > mbox ? 0 : mset.findi(a));
            break;
        }
    }
    return 0;
}