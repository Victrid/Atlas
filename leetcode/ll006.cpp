#include "lc.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> ans;
        vector<int> ret;
        while(head!=nullptr){
            ans.push(head->val);
            head=head->next;
        }
        while(!ans.empty()){
            ret.push_back(ans.top());
            ans.pop();
        }
        return ret;
    }
};