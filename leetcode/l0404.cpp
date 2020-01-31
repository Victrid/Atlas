#include "lc.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL),
 * right(NULL) {}
 * };
 */
//*BFS
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        queue<bool> leftleaf;
        q.push(root);
        leftleaf.push(false);
        while (!q.empty()) {
            if (q.front()->left == nullptr &&
                q.front()->right == nullptr) {
                if (leftleaf.front())
                    sum += q.front()->val;
            }
            if (q.front()->left != nullptr) {
                leftleaf.push(true);
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                leftleaf.push(false);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return sum;
    }
};