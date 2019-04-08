//水仙花数
#include<stdio.h>

const int low = 100;
const int high = 999;

int main(){
    int a,b,c;
    for(int i = low;i<=high;i++){
        a = i/100;
        b = i/10%10;
        c =i%10;
        if (i == a*a*a+ b*b*b + c*c*c)
            printf("%d ",i);
    }
    printf("\n");
}