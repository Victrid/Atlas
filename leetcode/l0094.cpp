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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> stack;
        TreeNode *a = new TreeNode(0);
        vector<int> ans;
        stack.push_back(root);
        while (stack.begin() != stack.end())
        {
            if (stack.back() == a)
            {
                //returned
                stack.pop_back();
                ans.push_back(stack.back()->val);
                if (stack.back()->right != NULL)
                {
                    TreeNode *temp = stack.back()->right;
                    stack.pop_back();
                    stack.push_back(temp);
                    continue;
                }
                stack.pop_back();
                continue;
            }
            if (stack.back() != NULL && stack.back()->left != NULL)
            {
                stack.push_back(a);
                stack.push_back(stack.back()->left);
                continue;
            }
            if (stack.back() != NULL)
                ans.push_back(stack.back()->val);
            if (stack.back() != NULL && stack.back()->right != NULL)
            {
                TreeNode *temp = stack.back()->right;
                stack.pop_back();
                stack.push_back(temp);
                continue;
            }
            stack.pop_back();
        }
        return ans;
    }
};