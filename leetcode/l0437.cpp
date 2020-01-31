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
class Solution {
public:
  int pathSum(TreeNode *root, int sum, int pathsum = 0) {
    int sums = 0;
    if (root == nullptr)
      return 0;
    if (pathsum + root->val == sum)
      sums++;
    if (root->left != nullptr) {
      if (!pathsum)
        sums += pathSum(root->left, sum, 0);
      if (pathsum + root->val != sum)
        sums += pathSum(root->left, sum, pathsum + root->val);
    }
    if (root->right != nullptr) {
      if (!pathsum)
        sums += pathSum(root->right, sum, 0);
      if (pathsum + root->val != sum)
        sums += pathSum(root->right, sum, pathsum + root->val);
    }
    return sums;
  }
};