/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *myhead=new ListNode(0);
        myhead->next=head;
        ListNode *pre=head;
        ListNode *cur=head->next;
      while(cur!=NULL){
         if(cur->val>=pre->val){
             pre=cur;
             cur=cur->next;
             
         }
         else{//cur<pre need find the insertion position
             ListNode *iter=myhead;
             while(iter->next->val<cur->val){
                 iter=iter->next;
             }// the insertion should between iter and iter->next
             
             pre->next=cur->next;// pre should first connet the nodes(even NULL) after cur;
             
             cur->next=iter->next;
             iter->next=cur;// after insert this current, the current poitn should move the pre->next;
             
             cur=pre->next;
         }
   
      }//end while
     return myhead->next;
    }
};
