/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL&&n==1){
            return NULL;
        }
        ListNode *myhead=new ListNode(0);
        myhead->next=head;
        ListNode *pre=myhead;
        ListNode *l2=pre; //remove 倒数第n个 两个指针间隔n-1 p1next开始第n-1个是p2
        int k=0;
        while(k<n){// put l2 point to the n position
            k=k+1;
            if(l2->next==NULL){
                break;
            }
            else{
            l2=l2->next;
            }
        }
        while(l2->next!=NULL){
            l2=l2->next;
            pre=pre->next;
        }
        if(l2->next==NULL){//pre->next is the one
            if(pre->next->next==NULL){
                pre->next=NULL;
            }
            else{
            pre->next=pre->next->next;
            }
        }
        return myhead->next;
    }
};
