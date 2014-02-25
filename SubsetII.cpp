/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > resultSet;
    vector<int> path;
    void helper(int currentdep,int submaxdep,int starter,vector<int> &S){
        if(currentdep==submaxdep){
            vector<vector<int> >::iterator it1=find(resultSet.begin(),resultSet.end(),path);
            if(it1==resultSet.end()){//never have path before then push this path
                resultSet.push_back(path);
            }
            return;
        }
      
        for(int i=starter;i<S.size();++i){
            path[currentdep]=S[i];
            helper(currentdep+1,submaxdep,i+1,S);
        }
        
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        for(int i=0;i<=S.size();++i){
            path.resize(i);
            helper(0,i,0,S);
        }
        return resultSet;
    }
};
