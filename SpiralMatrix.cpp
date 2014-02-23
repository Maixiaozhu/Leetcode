/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
       
        // int n=matrix[0].size();
        if(matrix.empty()==1){
            return result;
        }
        int m=matrix.size();
        int n=matrix[0].size();// cannot set matrix[0] to n if the matrix is empty 
         int start=0;
        while(start<=(n-1)/2&&start<=(m-1)/2){
            if(m-2*start==1){//只有一行
                for(int i=0;i<=n-1-2*start;++i){
                    result.push_back(matrix[start][start+i]);
                }
                return result;
            }
            else if(n-2*start==1){//只有一列
                for(int i=0;i<=m-1-2*start;++i){
                    result.push_back(matrix[start+i][n-1-start]);
                }
                return result;
            }
            else{
                for(int i=0;i<n-1-2*start;++i){//up do not include m[s][n-1-s]
                    result.push_back(matrix[start][start+i]);
                }
                for(int i=0;i<m-1-2*start;++i){//right include m[s][n-1-s] do not include m[m-1-s][n-1-s]
                    result.push_back(matrix[start+i][n-1-start]);
                }
                for(int i=0;i<n-1-2*start;++i){//bottom include m[m-1-s][n-1-s] do not include m[m-1-s][s]
                    result.push_back(matrix[m-1-start][n-1-start-i]);
                }
                for(int i=0;i<m-1-2*start;++i){//left include m[m-1-s][s] can not include m[s][s]
                    result.push_back(matrix[m-1-start-i][start]);
                }
            }
            
            start++;
        }
        return result;
        
    }
};
