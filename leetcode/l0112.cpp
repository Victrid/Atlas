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
//!wrong
//it seems that leetcode cannot process the static well.
//leaf means 
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        static bool first = true;
        if (root == nullptr)
        {
            if (sum||first)
                return false;
            else
                return true;
        }
        first = false;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};