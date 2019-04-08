#include<stdio.h>

int main(){
    int n;
    int hi,lo;
    for(int i = 1;;i++){
        n = i*i;
        if(n<1100) continue;
        if(n>9999) break;
        hi = n/100;
        lo = n%100;
        if(hi/10==hi%10&&lo/10==lo%10)
            printf("%d\n",n);
        
    }
    return 0;
}