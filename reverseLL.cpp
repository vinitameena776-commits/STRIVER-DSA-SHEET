#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//1️⃣ linear approach
// Function to reverse linked list
Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next; // store next
        curr->next = prev;          // reverse link
        prev = curr;                // move prev
        curr = forward;             // move curr
    }

    //kyuki ulta chlna h ab 
    return prev; // new head
}

//2️⃣ recursive approach 
Node* reverseRecursive(Node* head){
    //base case
    if(head == NULL || head->next == NULL) return head;

    Node*newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

// Function to print linked list
void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    // Creating Linked List: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printLL(head);

    // Reverse the linked list
    head = reverseLL(head);

    cout << "Reversed Linked List: ";
    printLL(head);
 
    head= reverseRecursive(head);
    cout << "After Recursive Reverse: ";
    printLL(head);
    return 0;
}