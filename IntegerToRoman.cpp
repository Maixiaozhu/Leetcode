/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    string getRoman(int bit,string one,string five,string ten){//bit 代表高位 只考虑高位是多少，输出 3百，3千，5百，4百
        string result="";
        switch(bit){
            case 0: result=result;
            break;
            case 1: result+=one;
            break;
            case 2: result+=one;
                    result+=one;
            break;
            case 3: result+=one;
                    result+=one;
                    result+=one;
            break;
            case 4: result+=one;
                    result+=five;
            break;
            case 5: result+=five;
            break;
            case 6: result+=five;
                    result+=one;
            break;
            case 7: result+=five;
                    result+=one;
                    result+=one;
            break;
            case 8: result+=five;
                    result+=one;
                    result+=one;
                    result+=one;
            break;
            case 9: result+=one;
                    result+=ten;
            break;
                 
        }
        return result;
    }
    string intToRoman(int num) {// 几千+ 几百+ 几十 + 几
        string ret="";
       vector<int> num2;
       while(num){
           num2.push_back(num%10);
           num=num/10;
       }
       //num2 存的是ix:0个位，ix:3 千位
       for(int i=num2.size()-1;i>=0;--i){//先算千位表达式再百位十位
           if(i==3){//千位
               ret+=getRoman(num2[i],"M","","");
           }
           if(i==2){//百位
               ret+=getRoman(num2[i],"C","D","M");
           }
           if(i==1){//十位
               ret+=getRoman(num2[i],"X","L","C");
           }
           if(i==0){//个位
               ret+=getRoman(num2[i],"I","V","X");
           }
       }
       return ret;
    }
};
