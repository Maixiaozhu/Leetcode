/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int C[200][200];
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++){
                C[i][j]=0;
            }
        }
        if(m>100||n>100){
            return 0;
        }
        for(int i=0;i<m+n-1;i++){ //yanghui triangle
            for(int j=0;j<=i;j++){
                //the start and end are 1
                if(j==i||j==0){
                    C[i][j]=1;
                }
                else{
                C[i][j]=C[i-1][j-1]+C[i-1][j];
                }
            
            }
        }
        return C[m+n-2][m-1];//如果是m行，n列的矩阵，机器人从左上走到右下总共需要的步数是n + m – 2，其中向下走的步数是m -1。因此问题变成                             //了在n + m -2个操作中，选择m – 1个时间点向下走，的选择方式有多少种。
        
        
    }
};
