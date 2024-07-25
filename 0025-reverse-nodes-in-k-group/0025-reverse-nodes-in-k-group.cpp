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
private:
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (k > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
    
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        int length = getLength(head);
        if (length < k) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* end = dummy;
        
        while (length >= k) {
            ListNode* groupStart = end->next;
            ListNode* groupEnd = groupStart;
            for (int i = 1; i < k; ++i) {
                groupEnd = groupEnd->next;
            }
            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;
            end->next = reverseList(groupStart, k);
            groupStart->next = nextGroupStart;
            end = groupStart;
            length -= k;
        }
        
        return dummy->next;
    }
};
