/*
THis problem is afte rotate image , what if the matrix rotates on the countclockwise?
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    //    if(matrix.size()==0||1){
      //      return;
        //}
       int n=matrix.size();
	   for(int start=0;start!=n/2;++start){
		   for(int i=0;i!=n-1-2*start;++i){
				int temp=matrix[start][start+i];
				matrix[start][start+i]=matrix[start+i][n-1-start];
		        matrix[start+i][n-1-start]=matrix[n-1-start][n-1-start-i];
		        matrix[n-1-start][n-1-start-i]=matrix[n-1-start-i][start];
				matrix[n-1-start-i][start]=temp;
		   }
	   }

    }
};
