//结构体定义 struct Point{double x,y;}; 
//常用方式typedef struct{double x, y;}Point;
//使用约分避免程序溢出 
//对复杂的表达式进行简化不仅能减少计算量，还能避免中间结果溢出
//
//素数判定
#include<stdio.h> 
#include<math.h> 
int is_prime(int n){
	if(n<=1)
		return 0;
	int m = floor(sqrt(n)+0.5);
	for (int i=2;i<+m;i++)
		if(n%i==0) return 0;
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",is_prime(n));
	return 0;
}

