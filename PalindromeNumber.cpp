/*
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
*/
class Solution {
public:
 
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        else if(x==0){
            return 1;
        }
        else{
            int y=x/10;
            int sum=x%10;
            int a;
            while(y){
                a=y%10;// a wil be update next time a start as the second last bit of x
                y=y/10;
                sum=sum*10+a;
            }
            if(sum==x){
                return 1;
            } 
            else{
                return 0;
            }
        }
    }
};
