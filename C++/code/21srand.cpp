//assert() ���ʽΪ��ʱ�ޱ仯������ǿ����ֹ���򣬲�������ʾ
//��STL ���в���
//srand() 
#include<iostream> 
using namespace std;
int main(){
	for(int i=2;i<100;i++){
		if((3*i-1)%20==0)
			cout<<i<<"\n";
	}
	return 0;
}
