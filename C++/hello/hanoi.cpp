#include<iostream>
using namespace std;

enum tower{
    A = 'A',
    B = 'B',
    C = 'C'
};

void TowerOfHanoi(int n, tower x,tower y, tower z){
    if(n){
        TowerOfHanoi(n-1,x,z,y);
        cout<<"move top disk form tower" <<char(x)
        <<"to top of tower" <<char(y)<<endl;
        TowerOfHanoi(n-1,z,y,x);
    }
}