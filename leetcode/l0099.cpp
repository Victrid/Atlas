#include "lc.hpp"
class Solution {
public:
    vector<TreeNode*>& mid(TreeNode* root, vector<TreeNode*>& v) {
        if (root == nullptr)
            return v;
        if (root->left != nullptr)
            mid(root->left, v);
        v.push_back(root);
        if (root->right != nullptr)
            mid(root->right, v);
        return v;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> i;
        i = mid(root, i);
        vector<TreeNode*>::iterator it;
        TreeNode *t1, *t2;
        for (it = i.begin(); it < i.end() - 1; it++) {
            if ((*it)->val >= (*(it + 1))->val)
                {t1 = *it;break;}
        }
        for (; it < i.end() - 1; it++) {
            if ((*it)->val >= (*(it + 1))->val)
                t2 = *(it+1);
        }
        if(t1!=nullptr&&t2!=nullptr)
        {int temp=t1->val;
        t1->val=t2->val;
        t2->val=temp;}
        return;
    }
};