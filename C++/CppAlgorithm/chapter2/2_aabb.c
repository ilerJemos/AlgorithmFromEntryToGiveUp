//形如aabb的完全平方数

#include<stdio.h>
#include<math.h>

int main(){
    int n,m;
    for(int a = 1;a<10;a++){
        for(int b = 0;b<10;b++){
            n = a*1100+b*11;
            m = floor(sqrt(n)+0.5);
            if(m*m ==n)
                printf("%d\n",n);
        }
    }
}