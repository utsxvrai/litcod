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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        
    
        
        ListNode *p = head;
        
        
        while(p->next!=nullptr && p!=nullptr){
            
            int a = p->val;

            
            int b = (p->next)->val;
            
            int gc = __gcd(a,b);
            
            ListNode* gcd_node = new ListNode(gc);
            gcd_node->next = p->next;
            p->next = gcd_node;
            p = gcd_node->next;
            
        }
        return head;
        
    }
};