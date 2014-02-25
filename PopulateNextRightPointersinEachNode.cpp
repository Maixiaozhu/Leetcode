/*Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //This is solution could solve problem1. it is trying to find whether a node is the last one in its level
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        if(root==NULL){
            return;
        }
        q.push(root);
       int currentsum=1;//root total numbe of nodes is 1
       int nextsum=0;
        while(q.empty()!=1){
            TreeLinkNode *temp=q.front();
            q.pop();
            currentsum=currentsum-1;
            if(temp->left!=NULL&&temp->right!=NULL){
                nextsum=nextsum+2; //calculat next level nodes number
                q.push(temp->left);//into queue;
                q.push(temp->right);
                
            }
            if(temp->left!=NULL&&temp->right==NULL){
                nextsum=nextsum+1;
                q.push(temp->left);
            }
            if(temp->right!=NULL&&temp->left==NULL){
                nextsum=nextsum+1;
                q.push(temp->right);
            }

            //after push check the pop one should pointer to next front or NULL
            if(currentsum==0){// this pop is the last node in this level
                temp->next=NULL;
                currentsum=nextsum;//move to next level
                nextsum=0;// nextsum clear to zero for next level
            }
            else{// current level still has nodes 
                temp->next=q.front();
            }
            
        }
        return;
        
    }
};
