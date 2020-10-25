#include "Tree.h"

// ==================== k-d tree ======================
kdTree::kdTree() {}

void kdTree::deleteSubTree(kdNode* root) {
    if (root == nullptr)
        return;
    deleteSubTree(root->left);
    deleteSubTree(root->right);
    delete root;
    return;
}

kdTree::~kdTree() { deleteSubTree(root); }

void kdTree::insert(kdNode*& root, int arr[], int dim) {
    if (root == nullptr) {
        root = new kdNode();
        memcpy(root->key, arr, sizeof(int) * 2);
        return;
    }
    if (memcmp(root->key, arr, sizeof(int) * 2) == 0)
        return;
    if (arr[dim % 2] > root->key[dim % 2])
        return insert(root->right, arr, dim + 1);
    else
        return insert(root->left, arr, dim + 1);
    return;
}

kdNode* kdTree::search(kdNode*& root, int arr[], int dim) {
    if (root == nullptr)
        return nullptr;
    if (memcmp(root->key, arr, sizeof(int) * 2) == 0)
        return root;

    if (arr[dim % 2] > root->key[dim % 2])
        return search(root->right, arr, dim + 1);
    else
        return search(root->left, arr, dim + 1);
    return nullptr;
}

void kdTree::importTree(kdNode*& newroot, kdNode* oldroot, int newrootdim) {
    if (oldroot == nullptr)
        return;
    insert(newroot, oldroot->key, newrootdim);
    importTree(newroot, oldroot->left, newrootdim);
    importTree(newroot, oldroot->right, newrootdim);
    return;
}

void kdTree::remove(kdNode*& root, int arr[], int dim) {
    if (root == nullptr)
        return;

    if (memcmp(root->key, arr, sizeof(int) * 2) == 0) {
        auto oldroot = root;
        root         = nullptr;
        importTree(root, oldroot->left, dim);
        importTree(root, oldroot->right, dim);
        deleteSubTree(oldroot);
        return;
    }

    if (arr[dim % 2] > root->key[dim % 2])
        return remove(root->right, arr, dim + 1);
    else
        return remove(root->left, arr, dim + 1);

    return;
}

kdNode* kdTree::findMin(kdNode*& root, int dimCmp, int dim) {
    if (root == nullptr)
        return nullptr;
    if (dimCmp == dim % 2) {
        return root->left == nullptr ? root
                                     : findMin(root->left, dimCmp, dim + 1);
    } else {
        kdNode* left  = findMin(root->left, dimCmp, dim + 1);
        kdNode* right = findMin(root->right, dimCmp, dim + 1);
        if (left == nullptr && right == nullptr)
            return root;
        auto mini = [=](kdNode* l, kdNode* r) {
            return l->key[dimCmp] > r->key[dimCmp] ? r : l;
        };
        if (left == nullptr)
            return mini(right, root);
        if (right == nullptr)
            return mini(root, left);
        return mini(mini(right, root), mini(root, left));
    }
}

vector<struct kdNode*> kdTree::rangeSearch(kdNode* root, int dim,
                                           int lower_bound[],
                                           int upper_bound[]) {
    vector<struct kdNode*> ansvector;
    rangeSearch(root, dim, lower_bound, upper_bound, ansvector);
    return ansvector;
}

void kdTree::rangeSearch(kdNode* root, int dim, int lb[], int ub[],
                         vector<struct kdNode*>& v_ans) {
    if (root == nullptr)
        return;
    if (lb[dim % 2] <= root->key[dim % 2])
        rangeSearch(root->left, dim + 1, lb, ub, v_ans);
    if (ub[dim % 2] > root->key[dim % 2])
        rangeSearch(root->right, dim + 1, lb, ub, v_ans);
    if (ub[0] >= root->key[0] && ub[1] >= root->key[1] &&
        lb[0] <= root->key[0] && lb[1] <= root->key[1])
        v_ans.push_back(root);
}

// ==================== trie (prefix tree) ======================
Trie::Trie() {
    root       = new TrieNode();
    root->flag = false;
    return;
}

void Trie::insert(string word) { return insert(root, word, 0); }

void Trie::insert(TrieNode* cur, const string& str, int pos) {
    if (str.size() == 0) {
        cur->flag = true;
        return;
    }
    if (str.size() == pos + 1) {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            cur->next.insert(
                std::pair<char, TrieNode*>(str.at(pos), new TrieNode()));
        cur->next[str.at(pos)]->flag = true;
        return;
    } else {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            cur->next.insert(
                std::pair<char, TrieNode*>(str.at(pos), new TrieNode()));
        return insert(cur->next[str.at(pos)], str, pos + 1);
    }
}

bool Trie::search(string word) { return search(root, word, 0); }

bool Trie::search(const TrieNode* cur, const string& str, int pos) {
    if (str.size() == 0)
        return cur->flag;
    if (str.size() == pos + 1) {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            return false;
        return cur->next.at(str.at(pos))->flag;
    } else {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            return false;
        return search(cur->next.at(str.at(pos)), str, pos + 1);
    }
}

bool Trie::exist(const TrieNode* cur) {
    if (cur == nullptr)
        return false;
    if (cur->flag == true)
        return true;
    for (auto i : cur->next)
        if (exist(i.second))
            return true;
    return false;
}
bool Trie::startsWith(string prefix) { startsWith(root, prefix, 0); }

bool Trie::startsWith(const TrieNode* cur, const string& str, int pos) {
    if (str.size() == 0)
        return exist(cur);
    if (str.size() == pos + 1) {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            return false;
        return exist(cur->next.at(str.at(pos)));
    } else {
        if (cur->next.find(str.at(pos)) == cur->next.end())
            return false;
        return startsWith(cur->next.at(str.at(pos)), str, pos + 1);
    }
}
