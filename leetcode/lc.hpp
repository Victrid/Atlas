/**
 * FILENAME:    LC.HPP
 * USAGE:       1] Provides includes to avoid lint error.
 *              2] Enables a compilable environment.
 *              3] Adds some useful functions to help debugging.
 * AUTHOR:      VictriD  https://github.com/VictriD
 * VERSION:     1.1.0   @DATE: 2020 Feb
 * 
 * UNDER MIT LICENSE.
 */

/**
 * FUNCTION:
 * TreeNode* ConstructTree(vector<int>&)
 *  Constructs a tree using vector<int> as same as leetcode provides.
 * ostream& operator<<(ostream& os, TreeNode* root)
 *  Print the tree into ostream. Defined as an override <<.
 * NAMESPACE HIDDEN_LEETCODE:
 *  int __HL__max(int,int)
 *      returns max number.
 *  int __HL__maxDepth(TreeNode*)
 *      returns max depth/height of a tree.
 *  int __HL__power(int,int)
 *      a simple power function returns $int_LEFT^int_RIGHT$
 * STRUCT TreeNode
 *  Provided by leetcode.
*/

#ifndef _LEETCODE_
#define _LEETCODE_

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <bitset>

#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#define null numeric_limits<int>::min()

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace HIDDEN_LEETCODE {
int __HL__max(int a, int b) {
    return a > b ? a : b;
}
int __HL__maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else
        return __HL__max(__HL__maxDepth(root->left) + 1, __HL__maxDepth(root->right) + 1);
}
int __HL__power(int num, int power) {
    if (power == 0)
        return 1;
    else if (power < 0)
        return 0;
    else
        return num * __HL__power(num, power - 1);
}
}; // namespace HIDDEN_LEETCODE

TreeNode* ConstructTree(vector<int>& input) {
    //* used to construct trees.
    queue<TreeNode**> queue_TreeNode;
    TreeNode* root = nullptr;
    for (auto i = input.begin(); i < input.end(); i++) {
        if (queue_TreeNode.empty()) {
            //root
            root = new TreeNode(*i);
            queue_TreeNode.push(&(root->left));
            queue_TreeNode.push(&(root->right));
            continue;
        }
        if (*i == null) {
            queue_TreeNode.front() = nullptr;
        } else {
            auto Subtree            = new TreeNode(*i);
            *queue_TreeNode.front() = Subtree;
            queue_TreeNode.push(&(Subtree->left));
            queue_TreeNode.push(&(Subtree->right));
        }
        queue_TreeNode.pop();
    }
    return root;
}

ostream& operator<<(ostream& os, TreeNode* root) {
    //*print the tree into stream.
    int depth = HIDDEN_LEETCODE::__HL__maxDepth(root);
    if (root == nullptr)
        return os;
    queue<TreeNode*> queue_treenode;
    TreeNode* ROW = new TreeNode(0);
    bool HasChild = false;
    queue_treenode.push(root);
    queue_treenode.push(ROW);
    int level = 1;
    while (!queue_treenode.empty()) {
        if (queue_treenode.front() == ROW) {
            queue_treenode.pop();
            os << endl;
            level++;
            if (!HasChild || queue_treenode.empty())
                break;
            queue_treenode.push(ROW);
            HasChild = false;
            continue;
        }
        os << (queue_treenode.front() == nullptr ? "^" : to_string(queue_treenode.front()->val));
        for (int i = 0; i < HIDDEN_LEETCODE::__HL__power(2, (depth - level)); i++) {
            os << "\t";
        }
        if (queue_treenode.front() != nullptr) {
            queue_treenode.push(queue_treenode.front()->left);
            queue_treenode.push(queue_treenode.front()->right);
            if (queue_treenode.front()->left != nullptr || queue_treenode.front()->right != nullptr)
                HasChild = true;
        } else {
            queue_treenode.push(nullptr);
            queue_treenode.push(nullptr);
        }
        queue_treenode.pop();
    }
    os << endl;
    return os;
}

#endif
