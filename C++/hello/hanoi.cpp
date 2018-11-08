#include<iostream>

using namespace std;

enum tower{
    A = '1',
    B = '2',
    C = '3'
};

void TowerOfHanoi(int n, tower x,tower y, tower z){
    if(n){
        TowerOfHanoi(n-1,x,z,y);
        cout<<"move top disk form tower " <<char(x)
        <<" to top of tower " <<char(y)<<endl;
        TowerOfHanoi(n-1,z,y,x);
    }
}

// int main(){
//     TowerOfHanoi(3,A,B,C);
//     return 0;
// }