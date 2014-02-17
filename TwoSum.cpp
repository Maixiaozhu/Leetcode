
class Solution {
public:
    struct Node{
        int value;
        int position;
        Node(int v=0,int pos=0):value(v),position(pos){}
        bool operator < (const Node &N) const{
            if( value==N.value) {
                return position<N.position;
            }
            else{
                return value<N.value;
            }
            
        }
    };
    vector<int> twoSum(vector<int> &numbers,int target){
        vector<Node> mynodes(numbers.size(),0);//initalize n nodes
        for(int ix=0;ix<numbers.size();++ix){
            
            mynodes[ix]=Node(numbers[ix],ix);// call selft-defined constructor
        }
        
	    sort(mynodes.begin(),mynodes.end());// using self defined operator operation
        for(int i=0;i<numbers.size();++i){
            int y=target-mynodes[i].value;
            int  low=min(i+1, (int)mynodes.size()-1);  
            int  high=mynodes.size()-1;
            while(low<=high){
                
                int mid=(low+high)/2;
                // each iteration the mid should be get from the current low and current high
                if(mynodes[mid].value==y){
                    vector<int> myindex;
                   myindex.push_back(min(mynodes[i].position+1,mynodes[mid].position+1));
                    myindex.push_back(max(mynodes[i].position+1,mynodes[mid].position+1));
                    return myindex;
                }
                else if(mynodes[mid].value>y){
                    high=mid-1;
                }
                else
                {  low=mid+1;
            
                }
        }
    }
    }
};
