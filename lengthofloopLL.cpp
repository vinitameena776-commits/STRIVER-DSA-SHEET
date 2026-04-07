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
   int lengthofloop(Node* head){
        unordered_map<Node* , int> nodemap;
        Node* temp=head;
        int timer=0;
        while(temp!=NULL){
            if(nodemap.find(temp)!=nodemap.end()){
                int looplength=timer-nodemap[temp];
                return looplength;
            }
            nodemap[temp]=timer;
            temp=temp->next;
            timer++;
        }
        return 0;
    }

   //OPTIMAL APPROACH
    int Lengthofloop(Node* head){
        Node* slow=head ;
        Node* fast=head;
        while(fast!=NULL && fast->next!= NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return countloopLength(slow);
            }
        }
        return 0;
    }

    int countloopLength(Node* meetingpoint){
        Node* temp=meetingpoint;
        int length=1;

        while(temp->next !=meetingpoint){
            temp=temp->next;
            length++;
        }
        return length;
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
    int LoopLength=sol.Lengthofloop(first);
    if(LoopLength > 0){
        cout<<"The length of loop is :"<<LoopLength<<endl;
    }

    // Create a Solution object
    Solution obj;
   int looplength=obj.lengthofloop(first);
        if (looplength > 0){
        cout<<"The length of loop is :"<<looplength<<endl;
    }
return 0;
}