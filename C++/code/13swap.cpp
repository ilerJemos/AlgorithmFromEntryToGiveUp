//swap
#include<stdio.h>
void swap(int* a,int* b){
	int t = *a;
	*a=*b;
	*b=t;
}
//错误写法1
//交换了函数的局部变量 a,b 
void swap1(int* a,int* b){
	int *t;
	*t=a;
	a=b;
	b=t;
}
//错误写法2
//野指针，指针指向的内存空间未知 
void swap2(int* a,int* b){
	int *t;
	*t = *a;
	*a=*b;
	*b=*t;
} 
int main(){
	int a=3,b=4;
	swap(a,b);
	printf("%d %d",a,b);
	return 0;
}
