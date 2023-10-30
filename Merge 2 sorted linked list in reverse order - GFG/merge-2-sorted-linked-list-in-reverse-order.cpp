//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * mergeResult(Node *h1,Node *h2)
{
   if (h1==NULL && h2==NULL) return NULL;
    Node *result = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            Node *temp = h1->next;
            h1->next = result;
            result = h1;
            h1 = temp;
        }
        else
        {
            Node *temp = h2->next;
            h2->next = result;
            result = h2;
            h2 = temp;
        }
    }
    while (h1 != NULL)
    {
        Node *temp = h1->next;
        h1->next = result;
        result = h1;
        h1 = temp;
    }
    while (h2 != NULL)
    {
        Node *temp = h2->next;
        h2->next = result;
        result = h2;
        h2 = temp;
    }
    
    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }

    
}