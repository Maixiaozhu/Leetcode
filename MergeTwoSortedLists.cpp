/*
Please do not use extra lists 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
     if(l1==NULL){
         return l2;
     }
     if(l2==NULL){
         return l1;
     }
     ListNode *currentNode=NULL;//let currentNode to rearrang the nodes'next connection in the original space
     ListNode *newHead=NULL;
     ListNode *iter1=l1;
     ListNode *iter2=l2;
     while(iter1&&iter2){
          if(iter1->val<iter2->val){
              if(newHead==NULL){
                  newHead=iter1;
                  //currentNode=iter1;
              }
              else{//已经有头
                  currentNode->next=iter1;
              }
              currentNode=iter1;//currentNode也要move到下一个点上 ++
              iter1=iter1->next;
          }
          else{
              if(newHead==NULL){
                  newHead=iter2;
                  //currentNode=iter2;//初始化newHead
              }
              else{//已经有头
                  currentNode->next=iter2;
              }
              currentNode=iter2;
              iter2=iter2->next;
          }
         
     }
     if(iter1){
         currentNode->next=iter1;
         
     }
     if(iter2){
         currentNode->next=iter2;
     }
     return newHead;
    }
};
