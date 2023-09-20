/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:

       int length(ListNode* head){
        if(!head){
            return 0;
        }
        return 1 + length(head->next);
    }
    int getDecimalValue(ListNode* head) {
        int ans =0;
        int l = length(head);
        ListNode* curr = head;

        

        while(curr!= NULL){
            if(curr->val == 1){
            ans += pow(2,l-1);
            
            }
            curr = curr->next;
            l--;
        }
        
        return ans;

    }
};