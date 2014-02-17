/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
Spoiler:
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
*/
class Solution {
public:
    int reverse(int x) {// for case x=1234
        int y=abs(x)/10;//initialize y=123 waiting to get "3"
        int sum=abs(x)%10;//initialize sum=4
        while(y){
            int a=y%10;
            y=y/10;//move back "<-" for next time to get a
            sum=sum*10+a;// sum=4*10+(1234/10)%10
        }
        if(x<0){
            return -1*sum;
        }
        else
        {
            return sum;
        }
    }
};
