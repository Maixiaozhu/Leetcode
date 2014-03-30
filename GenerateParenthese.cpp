/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> result;
    void dfs(int leftRemains,int rightRemains,stack<char> &currentLeftstack,string &path){
       if(leftRemains==0&&rightRemains==0&&currentLeftstack.empty()==1){
           result.push_back(path);
           return;
       }
       if(leftRemains>=1){//still have leftParenth left
           path.push_back('(');
           currentLeftstack.push('(');
           dfs(leftRemains-1,rightRemains,currentLeftstack,path);
           path.pop_back();
           currentLeftstack.pop();//each level has two choice, if choose '(', stack pass dfs should has is
                                 //if choose')', stack must pop out this '(' then pass inot dfs
       }
       if(rightRemains>=1&&currentLeftstack.empty()==0){//first time cannot push ')'
           path.push_back(')');//as soon as math the closed ')' in the top of stack, ')' mush pop out, before call dfs
           currentLeftstack.pop();
           dfs(leftRemains,rightRemains,currentLeftstack,path);//传下去的必须是 pop后的
           //对本层，需要还原 ')' 给另一个选择
           currentLeftstack.push(')');
           path.pop_back();//for other choices
           
       }
       
    }
    vector<string> generateParenthesis(int n) {
        if(n==0){
            return result;
        }
        stack<char> leftMatch;
        string path;
        dfs(n,n,leftMatch,path);
        return result;
   
        
    }
};
