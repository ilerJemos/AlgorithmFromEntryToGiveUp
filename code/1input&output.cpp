//�������뾶r�͸�h, ���Բ����ı������������λС��
//����ʹ��const�������� 
//pi = acos(-1.0)
//print("%a.bf") a:����������ռ��λ����b��С��������λ�� 
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
