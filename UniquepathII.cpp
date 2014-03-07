/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0){
            return 0;
        }
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> temp(n);
        vector<vector<int> > count(m,temp);
        //int count[m][n];//count matrix 储存路径数
        if(obstacleGrid[0][0]==1){
            count[0][0]=0;
        }
        if(obstacleGrid[0][0]==0){
            count[0][0]=1;
        }
        for(int i=1;i!=n;++i){
            if(obstacleGrid[0][i]==0){//看当前点是否可达，不可达为0
                count[0][i]=count[0][i-1];
            }
            else{
                count[0][i]=0;
            }
        }
        for(int i=1;i!=m;++i ){
            if(obstacleGrid[i][0]==0){
                count[i][0]=count[i-1][0];
            }
            else{
                count[i][0]=0;
            }
        }
        //count[i][j]:存的是(0,0)到(i,j)路径数 =(0,0)到(i-1,j)路径数+(0,0)到(i,j-1)路径数
        for(int ix=1;ix!=m;++ix){
            for(int jx=1;jx!=n;++jx){
                if(obstacleGrid[ix][jx]==0){
                count[ix][jx]=count[ix-1][jx]+count[ix][jx-1];// count[i-1][j] could be 0 if last iteration grid[i-1][j]=1
                }
                else{
                    count[ix][jx]=0;
                }
            }
        }//end for ix
        return count[m-1][n-1];
    }
};
