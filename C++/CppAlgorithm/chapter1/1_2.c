//输入华氏温度f
//输出摄氏温度c
//保留三位小数
//c = 5(f-32)/9

#include<stdio.h>

int main(){
    double f;
    scanf("%lf",&f);
    printf("%.3f\n",5*(f-32)/9);
    return 0;
}