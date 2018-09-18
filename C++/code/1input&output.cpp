//输入底面半径r和高h, 输出圆柱体的表面积，保留三位小数
//尽量使用const声明常数 
//pi = acos(-1.0)
//print("%a.bf") a:输出结果至少占的位数，b：小数点后面的位数 
#include<stdio.h>
#include<math.h>
int main(){
	const double pi = acos(-1.0);
//	printf("%7.3f",1.0/3);
	double h,r,s;
	scanf("%lf%lf",&h,&r);
	s= pi * r*r*2+2*pi*r*h;
	printf("%0.3lf",s);
	return 0;
}
