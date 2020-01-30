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
//!allwrong
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> q;
        TreeNode *ff = new TreeNode(1);
        q.push(root);
        q.push(ff);
        int level = 0;
        int lowlevel = 0;
        bool firstLeaf = true;
        bool hasChild = false;
        while (!q.empty())
        {
            if (q.front() != ff && firstLeaf && (q.front()->left == nullptr || q.front()->right == nullptr))
            {
                lowlevel = level;
                firstLeaf = false;
            }
            if (q.front() == ff)
            {
                if (hasChild)
                {
                    q.push(ff);
                    level++;
                }
                hasChild = false;
            }
            if (q.front()->left != nullptr)
            {
                q.push(q.front()->left);
                hasChild = true;
            }
            if (q.front()->right != nullptr)
            {
                q.push(q.front()->right);
                hasChild = true;
            }
            q.pop();
        }
        return (lowlevel + 1 >= level) ? true : false;
    }
};