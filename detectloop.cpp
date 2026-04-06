#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Solution{
    public:
    bool detectLoop(Node* head){
        Node* temp=head;
        unordered_map<Node* , int> nodemap;
        while(temp!=NULL){
            if(nodemap.find(temp)!=nodemap.end()){
                return true;
            }
            nodemap[temp]=1;
            temp=temp->next;
        }
        return false;
    }

   //OPTIMAL APPROACH
    bool findloop(Node* head){
        Node* slow=head ;
        Node* fast=head;
        while(fast!=NULL && fast->next!= NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
int main(){
 // Create nodes
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create loop
    fifth->next = third;

    //OPTIMAL SOLUTION
    Solution sol;
    if(sol.findloop(first)){
        cout<< "Loop detected in the linked list." << endl;
    }else{
        cout << "No loop detected in the linked list." << endl;
    }

    // Create a Solution object
    Solution obj;
    // Check if loop exists
    if (obj.detectLoop(first)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
return 0;
}