/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *helper(vector<int> &num,int low,int high){
       if(low==high){// for leaft it should not have next
           return NULL;
       }
        int mid=(low+high)/2;
        TreeNode *currentroot=new TreeNode(num[mid]);
        currentroot->left=helper(num,low,mid);//mid取不到， 取到的是mid-1 左边 [low,mid) 右边 [mid+1,high)
        currentroot->right=helper(num,mid+1,high);
        return currentroot;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size()==0){
            return NULL;
        }
        int low=0;
        int high=num.size();
        return helper(num,low,high);
        
    }
};
