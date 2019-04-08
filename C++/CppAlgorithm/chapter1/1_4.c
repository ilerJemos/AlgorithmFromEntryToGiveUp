//输入正整数n (n<360)
//输入n的正弦和余弦

#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("sin = %f\ncos = %f\n",sin(n),cos(n));
    return 0;
}