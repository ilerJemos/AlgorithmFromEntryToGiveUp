#include<stdio.h>

int main(){
    int a,b,c;
    double ans;

    int m,n;
    double decimal;

    freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&a,&b,&c)==3&&(a&&b&&c)){
        m = a/b;
        decimal = (double)a/b-m;
        for(int  i = 0;i<c;i++){
            decimal *= 10;
        }
        decimal += 0.5;
        printf("%d.%d\n",m,(int)decimal);
    }
    return 0;
}