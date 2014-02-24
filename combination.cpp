/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int> > resultSet;
   vector<int> path;
    void  helper(int currentdep, int maxdep,int starter,int n){
        if(currentdep==maxdep){
            resultSet.push_back(path);
            return;
        }
        for(int i=starter;i<=n;++i){
            //path.push_back(i);
            path[currentdep]=i;
            helper(currentdep+1,maxdep,i+1,n);//here currentdep+1, next recurive, will check currentdep+1?=maxdep, (for k=3)if cd=2,cd                                                       
                                               // cd+1==3 then push last path
        }
        
    }
    vector<vector<int> > combine(int n, int k) {
        path.resize(k);
        resultSet.clear();
        helper(0,k,1,n);
        return resultSet;
        
    }
   
};
