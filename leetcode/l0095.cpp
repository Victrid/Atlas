#include "lc.hpp"
class Solution {
public:
    struct ContinuousList {
        int start;
        int end;
    };
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        for (int i = 1; i <= n; i++) {
            TreeNode* rootptr        = new TreeNode(i);
            ContinuousList Leftlist = {1, i - 1}, Rightlist = {i + 1, n};
            vector<TreeNode*> TreeWithThisRoot = generateTrees(rootptr, Leftlist, Rightlist);
            ret.insert(ret.end(), TreeWithThisRoot.begin(), TreeWithThisRoot.end());
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(TreeNode* t, ContinuousList LeftList, ContinuousList rightlist) {
        vector<TreeNode*> AllLeftBranches, LeftBranch;
        vector<TreeNode*> AllRightBranches, RightBranch;
        vector<TreeNode*> ret;
        for (int i = LeftList.start; i <= LeftList.end; i++) {
            ContinuousList Leftlist{LeftList.start, i - 1}, Rightlist{i + 1, LeftList.end};
            TreeNode* LeftTreeRoot = new TreeNode(i);
            LeftBranch            = generateTrees(LeftTreeRoot, Leftlist, Rightlist);
            //core step: must be inserted
            AllLeftBranches.insert(AllLeftBranches.end(), LeftBranch.begin(), LeftBranch.end());
        }
        for (int j = rightlist.start; j <= rightlist.end; j++) {
            ContinuousList Leftlist{rightlist.start, j - 1}, Rightlist{j + 1, rightlist.end};
            TreeNode* RightTreeRoot = new TreeNode(j);
            RightBranch            = generateTrees(RightTreeRoot, Leftlist, Rightlist);
            AllRightBranches.insert(AllRightBranches.end(), RightBranch.begin(), RightBranch.end());
        }
        for (vector<TreeNode*>::iterator LeftBranch = AllLeftBranches.begin(); LeftBranch < AllLeftBranches.end(); LeftBranch++) {
            for (vector<TreeNode*>::iterator RightBranch = AllRightBranches.begin(); RightBranch < AllRightBranches.end(); RightBranch++) {
                TreeNode* CurrentRoot = new TreeNode(t->val);
                CurrentRoot->left     = *LeftBranch;
                CurrentRoot->right    = *RightBranch;
                ret.push_back(CurrentRoot);
            }
            if (AllRightBranches.begin() == AllRightBranches.end()) {
                TreeNode* CurrentRoot = new TreeNode(t->val);
                CurrentRoot->left     = *LeftBranch;
                CurrentRoot->right    = nullptr;
                ret.push_back(CurrentRoot);
            }
        }
        if (AllLeftBranches.begin() == AllLeftBranches.end()) {
            for (vector<TreeNode*>::iterator RightBranch = AllRightBranches.begin(); RightBranch < AllRightBranches.end(); RightBranch++) {
                TreeNode* CurrentRoot = new TreeNode(t->val);
                CurrentRoot->left     = nullptr;
                CurrentRoot->right    = *RightBranch;
                ret.push_back(CurrentRoot);
            }
            if (AllRightBranches.begin() == AllRightBranches.end()) {
                TreeNode* CurrentRoot = new TreeNode(t->val);
                CurrentRoot->left     = nullptr;
                CurrentRoot->right    = nullptr;
                ret.push_back(CurrentRoot);
            }
        }
        return ret;
    }
};