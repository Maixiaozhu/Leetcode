/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int pathsum[1000][1000];
    int minPathSum(vector<vector<int> > &grid) {
        
        if(grid.size()==0||grid[0].size()==0){
            return 0;
        }
        
        pathsum[0][0]=grid[0][0];
    
       
        //for grid[i][j] comes from either path[i][j-1]or path[i-1][j]
        for(int ix=1;ix!=grid[0].size();++ix){
            pathsum[0][ix]=pathsum[0][ix-1]+grid[0][ix];
        }
        for(int ix=1;ix!=grid.size();++ix){
            pathsum[ix][0]=pathsum[ix-1][0]+grid[ix][0];
        }
        
        for(int ix=1;ix!=grid.size();++ix){
            for(int jx=1;jx!=grid[0].size();++jx){
                pathsum[ix][jx]=min(pathsum[ix][jx-1],pathsum[ix-1][jx])+grid[ix][jx];
            }
        }
        
        return pathsum[grid.size()-1][grid[0].size()-1];
    }
};
