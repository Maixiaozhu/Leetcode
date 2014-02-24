/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
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
            resultSet.push_back(path);
            return;
        }
      
        for(int i=starter;i<S.size();++i){
            path[currentdep]=S[i];
            helper(currentdep+1,submaxdep,i+1,S);
        }
        
    }
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        for(int i=0;i<=S.size();++i){
            path.resize(i);
            helper(0,i,0,S);
        }
        return resultSet;
    }
};
