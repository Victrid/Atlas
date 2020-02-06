#include "lc.hpp"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*> q;
        TreeNode* ROW = new TreeNode(0);
        q.push(root);
        q.push(ROW);
        vector<int> ansrow;
        while(!q.empty()){
            if(q.front()==ROW){
                q.pop();
                ans.push_back(ansrow);
                ansrow.clear();
                if(q.empty())break;
                q.push(ROW);
                continue;
            }
            ansrow.push_back(q.front()->val);
            if(q.front()->left!=nullptr)q.push(q.front()->left);
            if(q.front()->right!=nullptr)q.push(q.front()->right);
            q.pop();
        }
        return ans;
    }
};