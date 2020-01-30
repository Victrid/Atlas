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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        return ToBST(nums, nums.begin(), nums.end() - 1);
    }
    //!iterator end indicates the first empty one but not last one
    TreeNode *ToBST(vector<int> &nums, vector<int>::iterator begin, vector<int>::iterator end)
    {
        int size = end - begin + 1;
        TreeNode *ret = nullptr;
        if (size >= 3)
        {
            ret = new TreeNode(*(begin + size / 2));
            ret->left = ToBST(nums, begin, begin + size / 2 - 1);
            ret->right = ToBST(nums, begin + size / 2 + 1, end);
        }
        if (size == 1)
        {
            ret = new TreeNode(*(begin));
        }
        if (size == 2)
        {
            ret = new TreeNode(*(end));
            ret->left = new TreeNode(*(begin));
        }
        return ret;
    }
};