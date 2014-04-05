/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
       
        vector<vector<int> > D(word1.size()+1,vector<int>(word2.size()+1));
        //D[i][j] string 1 from first char to the ith char(0-i-1)，string2 from firs char to jth char(0-j-1)
        //D[0][0] does not mean the first char, 1 is the firs char in D
          for(int i=0;i!=word1.size()+1;++i){
              D[i][0]=i;// word2 has no char, word1 has i chars, delete i times then get word2
          }
          for(int j=0;j!=word2.size()+1;++j){
              D[0][j]=j;//wor1 has no char, word2 has j chars, so inert i times get word2
          }
          for(int i=1;i<=word1.size();++i){
              for(int j=1;j<=word2.size();++j){
                  if(word1[i-1]==word2[j-1]){
                                            //notice you are not compare word1[i] and word2[j],where I made mistake first
                                            //you are comparing the ith and jth so its word1[i-1] word2[j-1]
                      D[i][j]=D[i-1][j-1];//no operation needed for this step
                  }
                  else{//word1[i]!=word2[j]
                      //one replace
                      D[i][j]=D[i-1][j-1]+1;//之前，即[i-1]和[j-1]有多少steps +1 这个1 是replace
                      D[i][j]=min(D[i][j],min(D[i-1][j]+1,D[i][j-1]+1));
                      //D[i-1][j], 是从i-1到j,insert一个，D[i][j-1]从i到j-1删一个
                  }
              }
          }
        return D[word1.size()][word2.size()];
    }
};
