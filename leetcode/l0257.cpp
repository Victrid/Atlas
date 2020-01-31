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
//*After changing stringpharse into & fasten the programme greatly.
class Solution
{
public:
    vector<string> &binaryTreePaths(TreeNode *root, vector<string> &ans, vector<TreeNode *> formerpath = vector<TreeNode *>())
    {
        if (root != nullptr)
            formerpath.push_back(root);
        else
            return ans;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(Pharse(formerpath));
            return ans;
        }
        if (root->left != nullptr)
        {
            binaryTreePaths(root->left, ans, formerpath);
        }
        if (root->right != nullptr)
        {
            binaryTreePaths(root->right, ans, formerpath);
        }
        return ans;
    }
    string Pharse(vector<TreeNode *> &q)
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
        binaryTreePaths(root, ans);
        return ans;
    }
};