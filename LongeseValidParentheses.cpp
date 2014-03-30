/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
note: for(()) ,it should return 2 instead of 4，that is where I am wrong at first.
*/
class Solution {
//isValid is used to store each elem in the string should be marked as true or false, 
//so this time the stack should not only push left parenth but right parenth, just check whether top is left to match,
//when it come accross the right parenth
public:
	int longestValidParentheses(string s) {
	stack<pair<char,int>> currentStack;
	vector<bool> isValid(s.size(),false);
	for(int ix=0;ix!=s.size();++ix){//
	   if(currentStack.empty()==1){
	       currentStack.push(make_pair(s[ix],ix));
	   }
	   else{
	       char currentTop=currentStack.top().first;
	       int topIndex=currentStack.top().second;
	       if(currentTop=='('&&s[ix]==')'){
	           currentStack.pop();//Only when ')' matches the '(' in the stack, can it delete the '('
	           isValid[topIndex]=true;//this topIndex and ix is adjacent closet mathc
	           isValid[ix]=true;
	       }
	       else{//currentTop could be')' just skip. push current char
	           currentStack.push(make_pair(s[ix],ix));
	       }
	   }
	}
	int currentLen=0;
	int result=0;
	for(int i=0;i!=s.size();++i){
	    if(isValid[i]==true){
	        currentLen++;
	    }
	    else{
	        result=max(currentLen,result);
	        currentLen=0;
	    }
	}
	result=max(result,currentLen);//if all the elem in S is marked ture, then in the end ,it will never check the result=max(current,result);
	return result;
	}
};
