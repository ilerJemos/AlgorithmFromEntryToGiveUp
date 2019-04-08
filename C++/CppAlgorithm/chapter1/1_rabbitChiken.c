//鸡兔同笼
//鸡兔总数n,总腿数m
//输出鸡和兔的数目
#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&n,&m);

    int a,b;
    a = (n*4-m)/2;
    b = n-a;
    if(a<0||b<0||m%2==1)
        printf("No Answer\n");
    else
        printf("%d %d\n",a,b);

    return 0;


}