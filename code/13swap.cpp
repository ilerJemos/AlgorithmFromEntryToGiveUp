//swap
#include<stdio.h>
void swap(int* a,int* b){
	int t = *a;
	*a=*b;
	*b=t;
}
//����д��1
//�����˺����ľֲ����� a,b 
void swap1(int* a,int* b){
	int *t;
	*t=a;
	a=b;
	b=t;
}
//����д��2
//Ұָ�룬ָ��ָ����ڴ�ռ�δ֪ 
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
