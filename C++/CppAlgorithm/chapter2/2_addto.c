//阶乘之和
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    long long fac;
    for(int i=1;i<=n;i++){
        fac = 1;
        for(int j = 1;j<=i;j++){
            fac*=j;
        }
        sum+=fac;
    }
    printf("%lld\n",sum%1000000);
    return 0;
}