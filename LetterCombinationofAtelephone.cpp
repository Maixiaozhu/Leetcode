/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    vector<string> result;
    map<char,string> keyMap;
    void setMap(){// I hate this part cause visit the content of a string by its index s[], I get a char instead of string
                 //So I have to make the type of this map to be<char,string>, but s.substr gets  you a string type result
        //keyMap.insert(map<string,string>::value_type("1"," "));
        //传递给insert的实参 OR make_pair
        keyMap.insert(make_pair('1'," "));
        keyMap.insert(make_pair('2',"abc"));
        keyMap.insert(make_pair('3',"def"));
        keyMap.insert(make_pair('4',"ghi"));
        keyMap.insert(make_pair('5',"jkl"));
        keyMap.insert(make_pair('6',"mno"));
        keyMap.insert(make_pair('7',"pqrs"));
        keyMap.insert(make_pair('8',"tuv"));
        keyMap.insert(make_pair('9',"wxyz"));
        keyMap.insert(make_pair('0'," "));
    }
    void helperdfs(int currentdep,int maxdep,string &digstr,string path){
        if(currentdep==maxdep){
            result.push_back(path);
            //path.clear();
            return;
        }
        //map.find return a pair-type iterator, member"first" return the key, member"second" return the value
        //using map.find could be better because it will not insert non-exist element 
        string currentdigits=keyMap.find(digstr[currentdep])->second;// if str="23" str[0] is 2 M.find(2) is pair iterator ,seconde meber
                                                                  //is "abc"
                                                                  //by currentdep to visit each digtis
        for(int i=0;i!=currentdigits.size();++i){
            //path=path+currentdigits.substr(i,1);//如果在这里迭代，path会变成当前的一个数字自己的所有可能性一一相加
            helperdfs(currentdep+1,maxdep,digstr,path+currentdigits.substr(i,1));//这样才是对递归函数选择当前curdigtis不同的字母
                                                                           //可以对下一层递归取到下一个digits的组合
        }
    }
    vector<string> letterCombinations(string digits) {
        
        setMap();
        helperdfs(0,digits.size(),digits,"");
        return result;
        
    }
};
