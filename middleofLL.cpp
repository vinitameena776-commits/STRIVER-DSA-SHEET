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
Node*find_middle(Node*head){
    if(head == NULL && head->next==NULL){
        return head;
    }

    int count=0;
    Node*temp=head;

    //Count nodes
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    //find middle
    int mid=(count/2); // for 1 based indexing cnt/2+1
    temp=head;

    //move to middle
    while (mid--) {
        temp = temp->next;
    }
    return temp;

}

//OPTIMAL APPROACH 
Node* findmiddle(Node*head){
    Node*slow=head ;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

int main(){
 Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findmiddle(head);
    Node*ans=find_middle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;
    cout << "The middle node value is: " << ans->data << endl;
return 0;
}