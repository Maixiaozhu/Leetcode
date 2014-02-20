/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode *myhead=new ListNode(0);
        ListNode *l1=myhead;
        l1->next=head;
        while(l1->next!=NULL&&l1->next->next!=NULL){
            if(l1->next->next->next==NULL){// last two nodes need to be swap
                ListNode *temp=l1->next->next;
                l1->next->next=NULL;
                temp->next=l1->next;
                l1->next=temp;
                break;
            }
            else{//  make node: l1->next connect to  l1->next->next->next then insert the original l1->next->next node between l1 and l1->next
            ListNode *temp=l1->next->next;
            l1->next->next=l1->next->next->next;// in this time l1's next node is l1->next
            temp->next=l1->next;// insert temp in l1 and l1->next
            l1->next=temp;
            }
            l1=l1->next->next;
            
        }//end while
        return myhead->next;
        
    }
};
