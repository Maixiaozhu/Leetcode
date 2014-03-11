/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if(root==NULL){
            return 0;
        }
        if(typeid(root->val)!=typeid(int)){
            return 0;
        }
       if(root->left==NULL&&root->right==NULL){
           return 1;
       }
        int leftmindep=minDepth(root->left);
        int rightmindep=minDepth(root->right);
        if(leftmindep==0&&rightmindep!=0){
            leftmindep=rightmindep+1;
        }
        if(rightmindep==0&&leftmindep!=0){
            rightmindep=leftmindep+1;
        }
        return min(leftmindep,rightmindep)+1;
    }
};
