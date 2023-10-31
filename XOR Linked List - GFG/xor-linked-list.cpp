//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> printList(struct Node *head);

int main() {
    int t;
    cin >> t;
    while (t--) {
        struct Node *head = NULL;
        int n, tmp;
        cin >> n;
        while (n--) {
            cin >> tmp;
            head = insert(head, tmp);
        }
        vector<int> vec = printList(head);
        for (int x : vec) cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->npx = XOR(head, NULL);

    if (head != NULL) {
        struct Node *next = XOR(head->npx, NULL);
        head->npx = XOR(newNode, next);
    }

    return newNode;
}

vector<int> printList(struct Node *head) {
    vector<int> result;
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL) {
        result.push_back(current->data);
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }

    

    return result;
}
