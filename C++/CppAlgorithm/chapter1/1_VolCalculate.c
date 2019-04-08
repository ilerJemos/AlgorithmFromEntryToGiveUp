//输入圆柱体的底面半径与高 输出表面积
#include<stdio.h>
#include<math.h>

int main(){
    float a,b;
    double pi = acos(-1.0);
    scanf("%f%f",&a,&b);
    printf("Area = %.3f\n",pi*a*a*2+2*pi*a*b);
    return 0;
}