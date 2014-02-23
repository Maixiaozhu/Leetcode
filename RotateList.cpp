/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(k==0){
            return head;
        }
        if(head->next==NULL&&k>=1){
            return head;
        }
        ListNode *p1=head;
        ListNode *t=head;
        ListNode *l2=head;
        int length=0;
        int d=0;
        while(t->next!=NULL){//get length
            t=t->next;
            length++;
        }
        
        if(k==(length+1)){
            return head;
        }
        else if(k>(length+1)){//update k
            k=k%(length+1);
            if(k==0){ // k can be divided by (length+1)
                return head;
            }
            else{// this time new k is always smaller than length
                while(l2->next!=NULL){
                    l2=l2->next;
                    if(d>=k){ // in here d is last d in case only have two node 
                        p1=p1->next;
                    }
                    d++; 
                }// p1->next is new ending
                ListNode *temp=p1->next;
                ListNode *newhead=temp;
                l2->next=head;
                p1->next=NULL;
                return newhead;
            }
        }
        
        else{//k<length+1
            while(l2->next!=NULL){
                l2=l2->next;
                
                if(d>=k){
                    p1=p1->next;
                }
                d++;
            }// p1->next is new ending
            ListNode *temp=p1->next;
            ListNode *newhead=temp;
            l2->next=head;
            p1->next=NULL;
            return newhead;
        }
        
    }
};
