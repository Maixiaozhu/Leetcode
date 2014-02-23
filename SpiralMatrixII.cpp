/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
       vector<vector<int> > result;
       if(n==0){
           return result;
       }
       result.resize(n);
       for(int i=0;i!=n;++i){
           result[i].resize(n);
       }
       int start=0;
      // int circle=0;
       int lastend=0;
       while(start<=(n-1)/2){
           if(n-2*start==1){
               for(int i=0;i<=n-1-2*start;++i){
                   result[start][start+i]=lastend+1+i;
               }
               return result;
           }
           else{
                for(int i=0;i<n-1-2*start;++i){//up do not include  r[s][n-1-s]
                    //result[start][start+i]=circle+i;
                    result[start][start+i]=lastend+1+i;
                }    
                for(int i=0;i<n-1-2*start;++i){//right
                    result[start+i][n-1-start]=result[start][n-1-start-1]+1+i;
                }
                for(int i=0;i<n-1-2*start;++i){//bottom
                    result[n-1-start][n-1-start-i]=result[n-1-start-1][n-1-start]+1+i;
                }
                for(int i=0;i<n-1-2*start;++i){//left
                    result[n-1-start-i][start]=result[n-1-start][start+1]+1+i;
                }
           }
            //circle=circle+4*(n-1-2*start)+1;//first calcule circle then start++
           lastend=result[start+1][start];
           start++;
              
           
       }//end while
    }
};
