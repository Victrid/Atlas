#include "lc.hpp"

class Solution {
public:
    vector<int>::iterator find(vector<int>& list, int num) {
        for (vector<int>::iterator f = list.begin(); f < list.end(); f++) {
            if (*f == num)
                return f;
        }
        return list.end();
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //root,left,right pre
        //left,root,right in
        if (preorder.begin() == preorder.end())
            return nullptr;
        int root                          = preorder.front();
        TreeNode* TreeRoot                = new TreeNode(root);
        vector<int>::iterator rootinorder = find(inorder, root);
        int leftsize                      = rootinorder - inorder.begin();
        vector<int> leftinorder(inorder.begin(), inorder.begin()+leftsize);
        vector<int> rightinorder(inorder.begin() + 1 + leftsize, inorder.end());
        vector<int> leftpreorder(preorder.begin() + 1, preorder.begin() + 1+ leftsize);
        vector<int> rightpreorder(preorder.begin() + 1 + leftsize, preorder.end());
        TreeRoot->left  = buildTree(leftpreorder, leftinorder);
        TreeRoot->right = buildTree(rightpreorder, rightinorder);
        return TreeRoot;
    }
};
int main(){
    Solution sol;
    vector<int> a = {3,9,20,15,7},b={9,3,15,20,7};
    sol.buildTree(a,b);
    return 0;
}