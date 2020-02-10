#include "lc.hpp"
class Solution {
public:
    void flatten(TreeNode* root) {
        //front sequence
        flatten_(root);
    }
    TreeNode* flatten_(TreeNode* root) {
        // returns the end of flattened linklist.
        if (root == nullptr)
            return nullptr;
        TreeNode* subroot = root->left != nullptr ? flatten_(root->left) : nullptr;
        TreeNode* leaf    = root->right != nullptr ? flatten_(root->right) : nullptr;
        if (subroot != nullptr) {
            subroot->right = root->right;
            root->right    = root->left;
            //! Must set empty here, or heap overflow will occur.
            root->left = nullptr;
        }
        if (leaf != nullptr)
            return leaf;
        else {
            return subroot != nullptr ? subroot : root;
        }
    }
};