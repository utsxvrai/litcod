//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
  
    Node* merge(Node* left, Node* right){
        Node* dummy = new Node(0);
        Node* current;
        current= dummy;
        
        while(left && right){
            
            if(left->data < right->data){
                current->next = left;
                left = left->next;
            }
            else{
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        if(left) current->next = left;
        
        if(right) current-> next = right;
        
        
        return dummy->next;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        if (!head || !head->next) {
        return head;
        }
        
        Node* temp= NULL;
        Node* fast=head;
        Node* slow=head;
        
        
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        temp->next = NULL;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(slow);
        
        
        return merge(left,right);
        
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends