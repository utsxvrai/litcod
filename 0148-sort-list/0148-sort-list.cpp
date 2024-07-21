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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while(temp != nullptr){
            arr.emplace_back(temp-> val);
            temp = temp-> next;

        }
        temp = head;
        int i =0;
        sort(arr.begin(), arr.end());
        while(temp != nullptr){
            temp-> val = arr[i];
            temp = temp-> next;
            i++;
        }
        
    return head;
    }
};