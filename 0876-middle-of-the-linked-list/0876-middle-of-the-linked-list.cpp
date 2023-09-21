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
    queue<ListNode*> q;
public:
    
        
    ListNode* middleNode(ListNode* head) {
        
        
        if( head != NULL )
        {
            while( head != NULL )
            {
                q.push(head);
                head = head->next;
            }
            int n = q.size()/2;
            while(n--)
                q.pop();
            return q.front();
        }
        return NULL;
        
        
        
    }
};