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
    
    ListNode* merge(ListNode* left,ListNode*right){
        if(left==NULL)return right;
        if(right==NULL)return left;

        //case1
        if(left->val <= right->val){
            left->next=merge(left->next,right);
            return left;
        }else{
            right->next=merge(left,right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* mid=slow->next;
        slow->next=NULL;

        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);

        return merge(left,right);
    }
};