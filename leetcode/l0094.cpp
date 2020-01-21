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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        ioT(root, ret);
        return ret;
    }
    vector<int> &ioT(TreeNode *root, vector<int> &pos)
    {
        if (root == NULL)
            return pos;
        ioT(root->left, pos);
        pos.push_back(root->val);
        ioT(root->right, pos);
        return pos;
    }
};