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
//*this solution is very slow and requires a lot memory.
class Solution
{
public:
    vector<vector<TreeNode *>> btp(TreeNode *root, vector<TreeNode *> infpath = vector<TreeNode *>())
    {
        vector<vector<TreeNode *>> ans;
        if (root != nullptr)
            infpath.push_back(root);
        else
            return ans;

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(infpath);
            return ans;
        }
        if (root->left != nullptr)
        {
            vector<vector<TreeNode *>> ret = btp(root->left, infpath);
            ans.insert(ans.end(), ret.begin(), ret.end());
        }
        if (root->right != nullptr)
        {
            vector<vector<TreeNode *>> ret = btp(root->right, infpath);
            ans.insert(ans.end(), ret.begin(), ret.end());
        }
        return ans;
    }
    string Pharse(vector<TreeNode *> q)
    {
        string a;
        bool rf = false;
        for (vector<TreeNode *>::iterator i = q.begin(); i < q.end(); i++)
        {
            if (rf)
                a += "->";
            a += to_string((*i)->val);
            rf = true;
        }
        return a;
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        vector<vector<TreeNode *>> bans = btp(root);
        for (vector<vector<TreeNode *>>::iterator i = bans.begin(); i < bans.end(); i++)
        {
            string b = Pharse(*i);
            if (b.length())
                ans.push_back(b);
        }
        return ans;
    }
};