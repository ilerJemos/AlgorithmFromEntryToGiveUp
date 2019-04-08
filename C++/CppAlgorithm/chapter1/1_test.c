#include<stdio.h>
#include<math.h>
int main(){
    printf("%d\n",2147483647);//int 最大值
    printf("%ld\n",sizeof(int));
    printf("%ld\n",sizeof(float));
    printf("%.2f\n",sqrt(10));
    printf("%.2f\n",pow(2,31));
    printf("%f\n",1.0/0.0);
    printf("%f\n",0.0/0.0);
    //printf("%d\n",1/0);
    printf("%%d\n");

    //输入输出实验
    int a,b;
    //scanf("%d%d",&a,&b);
    //printf("%d %d\n",a,b);
    return 0;
}