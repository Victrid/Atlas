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
//wrong
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> stack;
        vector<int> ans;
        stack.push_back(root);
        while (stack.begin() != stack.end())
        {
            TreeNode *hptr = stack.back();
            if (hptr->left != NULL)
            {
                stack.push_back(hptr->left);
                continue;
            }
            ans.push_back(hptr->val);
            if (hptr->right != NULL){
                stack.push_back(stack.pop_back()->right);
                continue;
            }
            stack.pop_back();
        }
        return ans;
    }
};