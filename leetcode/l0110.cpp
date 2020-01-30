#include "lc.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//* brute-force
class Solution
{
public:
    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int dd = depth(root->left) - depth(root->right);
        return (dd <= 1 && dd >= -1&&isBalanced(root->left) && isBalanced(root->right));
    }
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(depth(root->left), depth(root->right)) + 1;
    }
};