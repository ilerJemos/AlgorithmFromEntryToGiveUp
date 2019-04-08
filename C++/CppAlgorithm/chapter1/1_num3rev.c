//输入一个三位数
//分离出百位，十位和个位
//反转后输出

#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    printf("%d%d%d\n",a%10,a%100/10,a/100);
    return 0;
}