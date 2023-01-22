//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    
Node*reve(Node*head){
   if(head==NULL or head->next==NULL)return head;
   Node*prev=NULL,*curr=head,*forw=NULL;
   while(curr!=NULL){
       forw=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forw;
   }
   return prev;
}
Node*midfun(Node*head){
   if(head==NULL or head->next==NULL)return head;
   Node*slow=head,*fast=head;
   while(fast->next!=NULL and fast->next->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;
   }
   return slow;
   
}
    void reorderList(Node* head) {
        // Your code here
        Node* tmp = head;
    Node* mid = midfun(tmp);
    Node* newhead = mid->next;
    mid->next = NULL;
    newhead = reve(newhead);
    Node* c1 =head ;
    Node* c2=newhead;
    Node* f1=NULL;
    Node* f2=NULL;
    while(c2!=NULL){
        f1=c1->next;
        f2=c2->next;
        c1->next=c2;
        c2->next=f1;
        c1=f1;
        c2=f2;
    }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends