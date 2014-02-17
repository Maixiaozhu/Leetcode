/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
         if (l1 == NULL && l2 == NULL)
            return NULL;
            
        ListNode *head = NULL;
        ListNode *pre = NULL;
        int flag = 0;
        
        while(l1 && l2)
        {
            ListNode *node = new ListNode(l1->val + l2->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            ListNode *node = new ListNode(l1->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l1 = l1->next;
        }
        
        while(l2)
        {
            ListNode *node = new ListNode(l2->val + flag);
            flag = node->val / 10;
            node->val %= 10;
            
            if (head == NULL)
                head = node;
            else
                pre->next = node;
                
            pre = node;
            
            l2 = l2->next;
        }
        
        if (flag > 0)
        {
            ListNode *node = new ListNode(flag);
            pre->next = node;
        }
        
        return head;
    }//end of method 
};
