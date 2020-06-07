#include <cstdio>
#include <iostream>
using namespace std;
#include <cmath>
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
    size_t __size;
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
int main() {
    class tr : public AVL<int> {
    protected:
        node* i_qy(node* root, int& to_query, int& valuemin) {
            if (root == nullptr)
                return nullptr;
            if (root->value == to_query) {
                valuemin = 0;
                return root;
            }
            if (root->value > to_query) {
                if (root->value - to_query < valuemin)
                    valuemin = root->value - to_query;
                return i_qy(root->left, to_query, valuemin);
            }
            if (root->value < to_query) {
                if (to_query - root->value < valuemin)
                    valuemin = to_query - root->value;
                return i_qy(root->right, to_query, valuemin);
            }
            return nullptr;
        }

    public:
        int query(int& val) {
            int valuemin = abs(val - data->value);
            i_qy(data, val, valuemin);
            return valuemin;
        }
    } tree;
    int M, a, b;
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &a, &b);
        switch (a) {
        case 1:
            tree.insert(b);
            break;
        case 2:
            tree.erase(b);
            break;
        case 0:
            printf("%d\n", tree.query(b));
            break;
        }
    }
    return 0;
}