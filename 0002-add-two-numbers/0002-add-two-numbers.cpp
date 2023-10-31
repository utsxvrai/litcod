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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //simple way
        
        ListNode* l3 = new ListNode(0);
        ListNode* curr;
        curr = l3;
        int c=0;
        while(l1 and l2){
            int v = l1->val + l2->val+c;
            int n = v%10;
            c = v/10;
            
            ListNode* temp = new ListNode(n);
            curr->next = temp;
            curr = temp;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int v = l1->val+c;
            int n = v%10;
            c = v/10;
            
            ListNode* temp = new ListNode(n);
            curr->next = temp;
            curr = temp;
            
            l1 = l1->next;
        }
        while(l2){
            int v = l2->val+c;
            int n = v%10;
            c = v/10;
            
            ListNode* temp = new ListNode(n);
            curr->next = temp;
            curr = temp;
            
            l2 = l2->next;
        }
        if(c){
            ListNode* temp = new ListNode(c);
            curr->next = temp;
            curr = temp;
        }
        return l3->next;
        
    }
};