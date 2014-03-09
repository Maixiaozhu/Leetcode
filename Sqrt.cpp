/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/
class Solution {
public:
    int sqrt(int x) {
        if(x<=0){
            return 0;
        }
        long long start=1;
        long long end=x;
        while(start<=end){
            long long mid=(start+end)/2;
            long long compareRes=mid*mid;
            if(compareRes==x){
                return mid;
            }
            else if(compareRes<x){
                start=mid+1;
            }
            else{//compareRes>x
                end=mid-1;
            }
        }
        // when reach the end of while, start will be larger than end , so it sould return end
        return (int)end;
    }
};
