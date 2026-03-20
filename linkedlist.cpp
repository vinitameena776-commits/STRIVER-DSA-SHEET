#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* next;

   //CONSTRUCTOR
   Node(int data){
      this->data=data;
      this->next=NULL;
   }

   //DESTRUCTOR
   ~Node(){
      int value=this->data;
      if(this->next != NULL){
         delete next;
         this->next=NULL;
      }
      cout<<"memory is free for node with data"<< " "<<value <<endl;
   }
};

//refrence(&) isliye liya kyuki copy nhi bnana chahte jo orignal LL h uske andr hi change ho
void insertAthead(Node* &head,int value){
   
   //new node
   Node* temp=new Node(value);
   temp->next=head;
   head=temp;
}

void insertAttail(Node* &tail,int value){
   //new node
   Node* temp=new Node(value);
   tail->next=temp;
   tail= temp;
} 

void insertAtposition(Node* &tail,Node* &head,int position, int value){

   if(position==1){
      insertAthead(head,value);
   }

   Node* temp=head;
   int cnt=1;

   while(cnt < position-1){
      temp=temp->next;
      cnt++;
   }

   if(temp->next == NULL){
      insertAttail(tail,value);
   }
   //creating node for value
   Node* nodetoinsert=new Node(value);
   nodetoinsert ->next = temp->next;
   temp->next = nodetoinsert;
     
}

//TRAVERSE A LL
void print(Node* &head){
   Node* temp=head;

   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;//temp ko aage bda diya
   }
   cout<<endl;
}

void deletenode(int position,Node* &head ){

   //deleting first node
   if(position==1){
      Node* temp=head;
      head=head->next;
      temp->next=NULL;
      //to free memory of start node
      delete temp;
   }

   //deleting any position node or last node
   else{
      Node* current=head;
      Node* previous=NULL;
      int cnt=1;
      while(cnt < position){
         previous=current;
         current=current->next;
         cnt++;
      }
      previous->next=current->next;
      current->next=NULL;
      delete current;
   }
}

int main(){
//Created a new node in heap memory
Node* node1=new Node(10);

//head pointed to node1
Node* head=node1;
//tail also pointed to node 1 as only there is one element in LL
Node* tail=node1;
print(head);

insertAthead(head,12);
print(head);

insertAttail(tail,15);
print(head);//yaha head isliye liyea kyuki hmne jo print function bnaya h wo head ke liya tha

insertAtposition(tail,head,3,20);
print(head);

deletenode(1,head);
print(head);

return 0;
}