//倒三角形

#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int s = 0;
    while(n!=0){
        for(int j= 0;j<s;j++){
                printf(" ");
        }
        for(int i = 0;i<2*n-1;i++){
            printf("#");
        }
        printf("\n");
        n--;
        s++;
    }
}