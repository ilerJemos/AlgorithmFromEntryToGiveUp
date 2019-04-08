#include<stdio.h>

int main(){
    freopen("output.txt","w",stdout);
    for(int i = 1;i<20;i++){
        for(int j = i+1;j<=20;j++){
            printf("%d;%d;%d;%d\n",i,j,i+j,i*j);
        }
    }
    return 0;
}