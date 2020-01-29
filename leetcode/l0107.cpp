//Leetcode intro
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> Tq;
        stack<TreeNode *> Aq;
        TreeNode *Div = nullptr;
        Tq.push(root);
        Tq.push(Div);
        Aq.push(Div);
        bool HasChild = false;
        while (!Tq.empty())
        {
            if (Tq.front() == nullptr)
            {
                Tq.pop();
                Aq.push(Div);
                if (HasChild)
                {
                    Tq.push(Div);
                }
                HasChild = false;
                continue;
            }
            if (Tq.front()->right != nullptr)
            {
                Tq.push(Tq.front()->right);
                HasChild = true;
            }
            if (Tq.front()->left != nullptr)
            {
                Tq.push(Tq.front()->left);
                HasChild = true;
            }
            Aq.push(Tq.front());
            Tq.pop();
        }
        int iindex = -1;
        vector<int> tans;
        while (!Aq.empty())
        {
            TreeNode *tr = Aq.top();
            Aq.pop();
            if (tr == nullptr)
            {
                if (iindex != -1)
                {
                    ans.push_back(tans);
                }
                tans.clear();
                iindex++;
            }
            else
            {
                tans.push_back(tr->val);
            }
        }
        return ans;
    }
};