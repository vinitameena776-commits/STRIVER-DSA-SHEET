/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head==NULL)return NULL;

        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }
        if(cnt<k)return head;

        //reverse k node
        ListNode*next=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        cnt=0;

        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
            cnt++;
        }

        //recursion
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }

        //return head of reversed list
        return prev;
    }
};