//�˽��֧�ṹ��ƺ�˳��ṹ��� 
# include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	//����������
	int t;
	t=a;
	a=b;
	b=t;
	//����������
	 a=a+b;
	 b=a-b;
	 a=a-b;
	 //KISS
	 //keep it as simple and stupid
	 printf("%d %d",b,a); 
}
