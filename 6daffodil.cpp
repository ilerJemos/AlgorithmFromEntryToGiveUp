//水仙花数
//输出100~999中的所有水仙花数 
#include<stdio.h> 
int main(){
	int a,b,c;
	for(int i=100;i<1000;i++){
		a=i/100;
		b=i%100/10;
		c=i%10;
		if(i==a*a*a+b*b*b+c*c*c)
			printf("%d\n",i);
	}
	return 0;
}
