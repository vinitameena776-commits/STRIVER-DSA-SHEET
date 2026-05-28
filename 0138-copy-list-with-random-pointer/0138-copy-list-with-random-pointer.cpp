/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node (temp->val);
      //orignal node   copied version
            mp[temp] = copyNode;
            temp=temp->next;
        }

        temp=head;
        while(temp !=NULL){
             Node* copyNode=mp[temp]; //"Get the copied version of current original node."
            copyNode->next=mp[temp->next];
            copyNode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};