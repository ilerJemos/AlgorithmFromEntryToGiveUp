//生成1~n的排列
#include<iostream>

using namespace std;

void print_permutation(int n,int *a,int cur){
    if(cur==n){
        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    bool ok;
    for(int i = 1;i<=n;i++){
        ok = true;
        for(int j = 0;j<cur;j++){
            if(a[j]==i) {
                ok = false;
                break;
            }
            
        }
        if (ok){
                a[cur]=i;
                print_permutation(n,a,cur+1);
            }
    }
}
int main(){
    int n;
    cin>>n;
    int a[10];
    print_permutation(n,a,0);
    return 0;
}