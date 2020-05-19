#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//???Why?
unsigned long long bhash(char* c) {
    unsigned long long pc = 0;
    while (*c != '\0') {
        pc *= 131;
        pc += *c;
        c++;
    }
    return pc;
}
template <typename T1, typename T2>
struct paar {
    T1 __hash;
    T2 index;
    bool operator>(paar<T1, T2>& p) {
        return __hash > p.__hash;
    }
    bool operator<(paar<T1, T2>& p) {
        return __hash < p.__hash;
    }
    bool operator==(paar<T1, T2>& p) {
        return __hash == p.__hash;
    }
};

template <typename T>
class AVL {
protected:
    struct node {
        node* left;
        node* right;
        int height;
        T value;
    };
    node* data;
    int __size;
    node* i_query(node* root, T& to_query) {
        if (root == nullptr)
            return nullptr;
        if (root->value == to_query)
            return root;
        if (root->value > to_query) {
            return i_query(root->left, to_query);
        }
        if (root->value < to_query) {
            return i_query(root->right, to_query);
        }
    }
    void setrootheight(node* root) {
        if (root == nullptr)
            return;
        root->height = max((root->left == nullptr ? 0 : root->left->height), (root->right == nullptr ? 0 : root->right->height)) + 1;
    }

    node* right_rotate(node*& root) {
        node* nl   = root->left;
        root->left = nl->right;
        nl->right  = root;
        root       = nl;
        setrootheight(root->left);
        setrootheight(root->right);
        setrootheight(root);
        return root;
    }

    node* left_rotate(node*& root) {
        node* nr    = root->right;
        root->right = nr->left;
        nr->left    = root;
        root        = nr;
        setrootheight(root->left);
        setrootheight(root->right);
        setrootheight(root);
        return root;
    }

    inline int getfactor(node*& root) {
        if (root == nullptr)
            return 0;
        return (root->left == nullptr ? 0 : root->left->height) - (root->right == nullptr ? 0 : root->right->height);
    }

    int balance(node*& root) {
        if (root == nullptr)
            return 0;
        setrootheight(root->left);
        setrootheight(root->right);
        setrootheight(root);
        while (abs(getfactor(root->left)) > 1) {
            balance(root->left);
            setrootheight(root->left);
            setrootheight(root);
        }
        while (abs(getfactor(root->right)) > 1) {
            balance(root->right);
            setrootheight(root->right);
            setrootheight(root);
        }
        int p = getfactor(root);
        if (abs(p) <= 1)
            return 0;
        if (p > 0) {
            if (getfactor(root->left) == 1) {
                right_rotate(root);
                return 0;
            } else {
                left_rotate(root->left);
                right_rotate(root);
                return 0;
            }
        } else {
            if (getfactor(root->right) == -1) {
                left_rotate(root);
                return 0;
            } else {
                right_rotate(root->right);
                left_rotate(root);
                return 0;
            }
        }
    }

    int insert(node*& root, T& to_insert) {
        if (root == nullptr) {
            root = new node{nullptr, nullptr, 1, to_insert};
            __size++;
            return 0;
        }
        if (root->value < to_insert)
            insert(root->right, to_insert);
        else
            insert(root->left, to_insert);
        balance(root);
        return 0;
    }

    node* erasemin(node*& root) {
        if (root == nullptr)
            return nullptr;
        node* to_erase;
        if (root->left == nullptr) {
            to_erase = root;
            root     = root->right;
        } else {
            return erasemin(root->left);
        }
        balance(root);
        return to_erase;
    }

    int erase(node*& root, T& to_delete) {
        if (root == nullptr)
            return -1;
        if (root->value < to_delete)
            erase(root->right, to_delete);
        else if (root->value > to_delete)
            erase(root->left, to_delete);
        else if (root->value == to_delete) {
            __size--;
            node* rr = root;
            if (root->right == nullptr && root->left == nullptr) {
                root = nullptr;
            } else if (root->right == nullptr) {
                root = root->left;
            } else if (root->left == nullptr) {
                root = root->right;
            } else {
                node*& pp   = root->right;
                node* bl    = root->left;
                root        = erasemin(root->right);
                root->right = pp;
                root->left  = bl;
            }
            delete rr;
        }
        balance(root);
        return 0;
    }

public:
    AVL() : data(nullptr), __size(0){};
    int insert(T dat) {
        if (i_query(data, dat) != nullptr)
            return -1;
        else {
            insert(data, dat);
            return 0;
        }
    }
    int find(T dat) {
        return (i_query(data, dat) != nullptr);
    }
    int erase(T dat) {
        if (i_query(data, dat) == nullptr)
            return -1;
        else {
            erase(data, dat);
            return 0;
        }
    }
    int size() {
        return __size;
    }
};
class AVLtr : public AVL<paar<unsigned long long, int>> {
public:
    int test(unsigned long long t) {
        paar<unsigned long long, int> fp{t, __size + 1};
        node* f = i_query(data, fp);
        if (f == nullptr) {
            return -1;
        } else {
            return f->value.index;
        }
    }
};
int book[100005]   = {0};
int toremem[1005]  = {0};
int book_rem[1005] = {0};
inline bool checkrem(int n) {
    for (int i = 0; i < n; i++) {
        if (!toremem[i])
            continue;
        if (!book_rem[i])
            return false;
    }
    return true;
}
int main() {
    int n, m;
    scanf("%d", &n);
    char ch[100];
    AVLtr torem;
    for (int i = 0; i < n; i++) {
        scanf("%s", ch);
        torem.insert(paar<unsigned long long, int>{bhash(ch), i});
    }
    scanf("%d", &m);
    int exist_torem = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", ch);
        book[i] = torem.test(bhash(ch));
        if (book[i] != -1 && !toremem[book[i]]) {
            toremem[book[i]] = 1;
            exist_torem++;
        }
    }
    if (!exist_torem) {
        printf("0\n0");
        return 0;
    }
    // I was wrong.
    // two pointer method.
    // missing unchecked
    int *ptrl = book, *ptrr = book;
    book_rem[*ptrr]++;
    int flag = 0;
    int maxl = m;
    while (ptrr < book + m) {
        if (!checkrem(n)) {
            if (flag != 0) {
                maxl = min(maxl, flag);
            }
            ptrr++;
            if (*ptrr != -1) {
                book_rem[*ptrr]++;
            }
            flag = 0;
        } else {
            flag = ptrr - ptrl + 1;
            book_rem[*ptrl]--;
            ptrl++;
        }
    }
    printf("%d\n%d", exist_torem, maxl);
    return 0;
}