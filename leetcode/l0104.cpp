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
    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};