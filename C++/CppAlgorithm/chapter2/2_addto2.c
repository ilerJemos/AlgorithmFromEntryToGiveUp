//溢出和计时函数

#include<stdio.h>
#include<time.h>

int main(){
    const int MOD = 1000000;
    int n,sum= 0,fac = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        fac = 1;
        for(int j = 1;j<=i;j++){
            fac = (fac*j)%MOD;
        }
        sum = (sum+fac)%MOD;
    }
    printf("%d\n",sum);
    printf("Time used =%.2f\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}