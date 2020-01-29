#include <queue>
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 using namespace std;

 class Solution
 {
 public:
     //BFS
     bool isSymmetric(TreeNode *root)
     {
         if (root == nullptr)
             return true;
         queue<TreeNode *> leftq, rightq;
         if (root->left == nullptr ^ root->right == nullptr)
             return false;
         if (root->left == nullptr)
             return true;
         if (root->left->val != root->right->val)
             return false;
         leftq.push(root->left);
         rightq.push(root->right);
         while (!leftq.empty())
         {
             //structure symmetric
             if (leftq.front()->left == nullptr ^ rightq.front()->right == nullptr)
                 return false;
             if (leftq.front()->right == nullptr ^ rightq.front()->left == nullptr)
                 return false;
             //value symmetric
             if (leftq.front()->left != nullptr)
             {
                 if (leftq.front()->left->val == rightq.front()->right->val)
                 {
                     leftq.push(leftq.front()->left);
                     rightq.push(rightq.front()->right);
                 }
                 else
                     return false;
             }
             if (leftq.front()->right != nullptr)
             {
                 if (leftq.front()->right->val == rightq.front()->left->val)
                 {
                     leftq.push(leftq.front()->right);
                     rightq.push(rightq.front()->left);
                 }
                 else
                     return false;
             }
             leftq.pop();
             rightq.pop();
         }
         return true;
     }
};
