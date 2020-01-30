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
//*BFS
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> tq;
        TreeNode *Empty = new TreeNode(0);
        tq.push(root);
        tq.push(Empty);

        int level = 1;
        bool HasChild = false;

        while (!tq.empty())
        {
            if (tq.front() == Empty)
            {
                tq.pop();
                if (HasChild)
                {
                    tq.push(Empty);
                    level++;
                }
                continue;
            }
            if (tq.front()->left == nullptr && tq.front()->right == nullptr)
            {
                return level;
            }
            if (tq.front()->left != nullptr)
            {
                HasChild = true;
                tq.push(tq.front()->left);
            }
            if (tq.front()->right != nullptr)
            {
                HasChild = true;
                tq.push(tq.front()->right);
            }
            tq.pop();
        }

        return level;
    }
};