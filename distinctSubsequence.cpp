/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.size()==0){
            return 0;
        }
        int m=S.size();
        int n=T.size();
        vector<vector<int> > f(m,vector<int>(n));
        if(S[0]==T[0]){
            f[0][0]=1;
        }
        else{
            f[0][0]=0;
        }
        for(int i=1;i<m;++i){
            if(S[i]!=T[0]){
                f[i][0]=f[i-1][0];
            }
            else{
                f[i][0]=f[i-1][0]+1;
            }
        }
        for(int j=1;j<n;++j){
            f[0][j]=0;//j是从 T的第二个开始到T的第n(n-1)个，在S的第一个中永远找不到
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){

                if(S[i]!=T[j]){
                    f[i][j]=f[i-1][j];
                }
                else{
                    f[i][j]=f[i-1][j-1]+f[i-1][j];//如果选择i, j来做match, 和f[i-1][j-1]结果一样，
                                         //还有可能，不选S中的i，T[j]已经可以match,比如，T[j]这个值在 
                                         //S[i-1]之前已经出现过，可以不选，是一种distinct
                }
                
        
            }
        }
        return f[m-1][n-1];
    }
};
