/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(ListNode *head, ListNode *end){
        if(head==end){
            return NULL;
        }
  
      ListNode *ite=head;
      ListNode *p=head;
      int step=0;
      while(ite->next!=end){
          ite=ite->next;
           step++;
          if(step%2==0){//当ite跑了两步时，p才开始跑一步
              p=p->next;
          }
         
      }
      TreeNode *currentroot=new TreeNode(p->val);
      currentroot->left=helper(head,p);//[head,p(mid)) in case that list cannot get mid-1 next recusive, iter will stop in mid-1(iter 
                                     //->next!=end)
      currentroot->right=helper(p->next,end);
      return currentroot;
      
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
       return helper(head,NULL);
    }
};
