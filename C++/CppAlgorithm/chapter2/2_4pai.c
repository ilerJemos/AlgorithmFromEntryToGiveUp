#include<stdio.h>

int main(){
    double sum=0;
    double term = 0;
    int i = 0;
    do{
        term =1.0/(i*2+1) ;
        if(i%2==0)
            sum-=term;
        else
            sum+=term;
        i++;
    }while(term>=1e-6);
    printf("%.6f\n",sum);
    return 0;
}