//sum
#include<stido.h> 
int sum1(int* begin,int*end){
	int n = end - begin;
	int ans =0;
	for (int i=0;i<n;i++){
		ans+=begin[i];
	}
	return ans;
}
int sum2(int*begin , int* end){
	int *p = begin;
	int ans =0;
	for(*p=begin;p!=end;p++){
		ans+=*p;
	}
	return ans;
}
