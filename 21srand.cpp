//assert() 表达式为真时无变化，否则强行终止程序，并给出提示
//对STL 进行测试
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
