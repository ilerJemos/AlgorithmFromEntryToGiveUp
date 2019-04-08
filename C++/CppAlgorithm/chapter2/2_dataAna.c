//输出最大值，最小值，平均值
//输入长度不确定

#define LOCAL

#include<stdio.h>
#define INF 1000

int main(){
    
    #ifdef LOCAL
    //输入输出框架
    //重定向
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int x,s=0,n = 0;
    int min=INF;
    int max=-INF;
    while(scanf("%d",&x)==1){
        s+=x;
        n++;
        if(x<min)
            min = x;
        if(x>max)
            max = x;
    }
    printf("%d %d %.3f\n",min,max,(double)s/n);
    return 0;
}