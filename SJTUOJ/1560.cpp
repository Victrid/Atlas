#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node {
    long long value;
    node* left;
    node* right;
};
class BST {
public:
    node* __root;
    node* query(node* root, long long& to_query) {
        if (root == nullptr)
            return nullptr;
        if (root->value == to_query)
            return root;
        if (root->value > to_query) {
            return query(root->left, to_query);
        }
        if (root->value < to_query) {
            return query(root->right, to_query);
        }
        return nullptr;
    }
    node* queriy(node* root, long long& to_query, char*& buffer) {
        if (root == nullptr)
            return nullptr;
        if (root->value == to_query)
            return root;
        if (root->value > to_query) {
            sprintf(buffer, "l");
            buffer++;
            return queriy(root->left, to_query, buffer);
        }
        if (root->value < to_query) {
            sprintf(buffer, "r");
            buffer++;
            return queriy(root->right, to_query, buffer);
        }
        return nullptr;
    }
    int insert(node*& root, long long& to_insert) {
        if (root == nullptr) {
            root = new node{to_insert, nullptr, nullptr};
            return 0;
        }
        if (root->value < to_insert)
            insert(root->right, to_insert);
        else if (root->value > to_insert)
            insert(root->left, to_insert);
        else
            return 0;
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
        return to_erase;
    }

    int erase(node*& root, long long& to_delete) {
        if (root == nullptr)
            return -1;
        if (root->value < to_delete)
            erase(root->right, to_delete);
        else if (root->value > to_delete)
            erase(root->left, to_delete);
        else if (root->value == to_delete) {
            node* rr = root;
            if (root->right == nullptr && root->left == nullptr) {
                root = nullptr;
            } else if (root->right == nullptr) {
                root = root->left;
            } else {
                node*& pp   = root->right;
                node* bl    = root->left;
                root        = erasemin(root->right);
                root->right = pp;
                root->left  = bl;
            }
            delete rr;
        }
        return 0;
    }
    BST() : __root(nullptr){};
};

int main() {
    int n;
    long long op;
    char ch;
    char buffer[10000];
    BST b;
    scanf("%d", &n);
    while (n--) {
        scanf("\n%c %lld", &ch, &op);
        switch (ch) {
        case '+':
            b.insert(b.__root, op);
            break;
        case '-':
            b.erase(b.__root, op);
            break;
        case '*':
            char* buf = buffer;
            sprintf(buf, "*");
            buf++;
            void* j = b.queriy(b.__root, op, buf);
            sprintf(buf, "\n");
            buf++;
            *buf = '\0';
            if (j == nullptr) {
                printf("Nothing.\n");
            } else {
                printf("%s", buffer);
            }
            break;
        }
    }
    return 0;
}