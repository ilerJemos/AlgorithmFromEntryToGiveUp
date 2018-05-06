//了解分支结构设计和顺序结构设计 
# include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	//三变量交换
	int t;
	t=a;
	a=b;
	b=t;
	//两变量交换
	 a=a+b;
	 b=a-b;
	 a=a-b;
	 //KISS
	 //keep it as simple and stupid
	 printf("%d %d",b,a); 
}
