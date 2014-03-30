/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
  
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
 
       stack<char> currentStack;
        for(int ix=0;ix!=s.size();++ix){
        
            switch(s[ix]){
                case '(': 
                   currentStack.push(s[ix]);
                    break;
                case '[':
                    currentStack.push(s[ix]);
                    break;
                case '{':
                    currentStack.push(s[ix]);
                    break;
                    
                case ')':
                 
                        if(currentStack.empty()==1){
                            return false;
                        }
                        else{
                            if(currentStack.top()=='('){
                                currentStack.pop();
                            }
                            else{
                                return false;
                            }
                        
                        }
                    break;
                case ']':
    
                 
                        if(currentStack.empty()==1){
                            return false;
                        }
                        else{
                            if(currentStack.top()=='['){
                                currentStack.pop();
                            }
                            else{
                                return false;
                            } 
                        }
                    
                    break;
                case '}':
         
                  
                        if(currentStack.empty()==1){
                            return false;
                        }
                        else{
                            if(currentStack.top()=='{'){
                                currentStack.pop();
                            }
                            else{
                                return false;
                            }
                        }
               
                    break;
                default:
                    return false;
                    
            }
        }//end for
        if(currentStack.empty()==1){
            return true;
        }
        else{
            return false;
        }
        
    }
};
