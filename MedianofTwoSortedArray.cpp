/*
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution{
public:
	double findkthoftwoarray(int A[], int m, int B[], int n, int k)// k is the kth element instead of index "k", which is index k-1
	{
	if (m>n){//make sure that m is smaller
    	return findkthoftwoarray(B,n,A,m,k);
    }
    if(m==0){// when the smaller is empty
	    return B[k-1];
	}

    if(k<=1){ // if k=1 while A is empty it should be B[0] not the minume:A[0]
		return min(A[0],B[0]);
	}

	int indexA=min(k/2,m);int indexB=k-indexA;
	
	if(A[indexA-1]<B[indexB-1]){
		return findkthoftwoarray(A+indexA,m-indexA,B,n,k-indexA);
	}
	else if(A[indexA-1]>B[indexB-1]){
		return findkthoftwoarray(A,m,B+indexB,n-indexB,k-indexB);
	}
	else{
		return A[indexA-1];
	}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n){
	   	int lengthAB=m+n;
	if(lengthAB%2!=0){
	     return findkthoftwoarray(A,m,B,n,(lengthAB+1)/2);
	}
	else{
		return (findkthoftwoarray(A,m,B,n,lengthAB/2)+findkthoftwoarray(A,m,B,n,lengthAB/2+1))/2;
	
	} 
	}
};

