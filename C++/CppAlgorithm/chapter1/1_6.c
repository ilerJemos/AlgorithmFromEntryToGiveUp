//
#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int t;
    if(a>c){
        t = a;
        a = c;
        c = a;
    }
    if(b>c){
        t = b;
        b = c;
        c = t;
    }
    if(a+b<=c)
        printf("not a triangle\n");
    else if(a*a+b*b == c*c)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}