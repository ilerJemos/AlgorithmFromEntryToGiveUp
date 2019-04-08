//

#include<stdio.h>

const int a = 95;

int main(){
    int n;
    scanf("%d",&n);
    if(a*n>=300)
        printf("%.2f\n",0.85*a*n);
    else
        printf("%.2f\n",1.0*a*n);
    return 0;
}