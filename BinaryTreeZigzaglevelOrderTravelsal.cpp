/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int> > resultSet;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        if(root==NULL){
            return resultSet;
        }
        q.push(root);
        int currentsum=1;
        int currentlevel=1;
        int nextsum=0;
        vector<int> tempvec;
        while(q.size()!=0){
            TreeNode *temp=q.front();
            tempvec.push_back(temp->val);
            q.pop();
            currentsum=currentsum-1;
            if(temp->left!=NULL&&temp->right!=NULL){
                nextsum=nextsum+2;
                q.push(temp->left);
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
            if(currentsum==0){//move to nextlevel
                currentsum=nextsum;
                nextsum=0;
                if(currentlevel%2!=0){
                    resultSet.push_back(tempvec);
                }
                else{
                    vector<int> retempvec;
                    for(int ix=tempvec.size()-1;ix>=0;--ix){
                        retempvec.push_back(tempvec[ix]);
                    }
                    resultSet.push_back(retempvec);
                   // retempvec.clear();
                }
                tempvec.clear();// every time have to clear tempvec outside if-else because at even level, 
                                //program is not going to into "if" scope, then, tempvec will still have last level nodes inside
                                //each time into next level,tempvec should be completely clear incase [1] [3,2] [2,3,4,5]
                
                 currentlevel++;
            }
        }
        return resultSet;
    }
};
