#include "lc.hpp"
class Solution {
public:
vector<int> &mid(TreeNode* root,vector<int> &v){
    if(root==nullptr)return v;
    if(root->left!=nullptr)mid(root->left,v);
    v.push_back(root->val);
    if(root->right!=nullptr)mid(root->right,v);
    return v;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> i;
        i = mid(root,i);
        if((i.end()-i.begin())<=1)return true;
        for(vector<int>::iterator it=i.begin();it<i.end()-1;it++){
            if(*it>=*(it+1))return false;
        }
        return true;
    }
};