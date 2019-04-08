#include<map>
#include<vector>
#include<queue>
#include<set>
#include<iostream>

using namespace std;

typedef long long LL;
const int coeff[3]={2,3,5};

int main(){
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    set<LL> s;

    pq.push(1);
    s.insert(1);
    LL x;
    for(int i = 1;i<=1500;i++){
        x= pq.top();
        pq.pop();
        if(i==1500){
            cout << "th e 1500th  ugly number is "<<x<<endl;
        }
        for(int j = 0;j<3;j++){
            LL x2 = x*coeff[j];
            if(!s.count(x2)){
                pq.push(x2);
                s.insert(x2);
            }
        }
    }
    return 0;

}