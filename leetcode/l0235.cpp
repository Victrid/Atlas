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
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
            return root == p ? p : q;
        if ((root->val - p->val) * (root->val - q->val) > 0)
            return lowestCommonAncestor(root->val - p->val > 0 ? root->left : root->right, p, q);
        else
            return root;
    }
};