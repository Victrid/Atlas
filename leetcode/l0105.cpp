#include "lc.hpp"

class Solution {
public:
    vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int num) {
        for (vector<int>::iterator f = begin; f < end; f++)
            if (*f == num)
                return f;
        return end;
    }
    TreeNode* buildTree(vector<int>::iterator pbegin, vector<int>::iterator pend, vector<int>::iterator ibegin, vector<int>::iterator iend) {
        if (pbegin == pend)
            return nullptr;
        int root                          = *pbegin;
        TreeNode* TreeRoot                = new TreeNode(root);
        vector<int>::iterator rootinorder = find(ibegin, iend, root);
        int leftsize                      = rootinorder - ibegin;
        TreeRoot->left                    = buildTree(pbegin + 1, pbegin + 1 + leftsize, ibegin, ibegin + leftsize);
        TreeRoot->right                   = buildTree(pbegin + 1 + leftsize, pend, ibegin + 1 + leftsize, iend);
        return TreeRoot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end()); }
};