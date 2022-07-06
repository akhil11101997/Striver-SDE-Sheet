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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev=NULL;
        ListNode* head=l1;
        int carry=0;
        while(l1 && l2){
            int temp=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1->val=temp;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
        while(l1){
            int temp=(l1->val+carry)%10;
            carry=(l1->val+carry)/10;
            l1->val=temp;
            prev=l1;
            l1=l1->next;
        }
        if(carry==0){
            return head;
        }
        ListNode* newNode=new ListNode(carry);
        prev->next=newNode;
        return head;
        }
        prev->next=l2;
        while(l2){
            int temp=(l2->val+carry)%10;
            carry=(l2->val+carry)/10;
            l2->val=temp;
            prev=l2;
            l2=l2->next;
        }
        if(carry==0){
            return head;
        }
        ListNode* newNode=new ListNode(carry);
        prev->next=newNode;
        return head;
    }
};
