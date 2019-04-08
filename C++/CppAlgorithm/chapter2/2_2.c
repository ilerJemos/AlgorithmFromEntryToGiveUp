//韩信点兵

#include<stdio.h>

#define LOCAL

const int low = 10;
const int high = 100;

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    int a,b,c;
    int kase = 0;
    int flg;
    while(scanf("%d%d%d",&a,&b,&c)==3){
        kase++;
        flg =0;
        printf("Case %d: ",kase);
        for(int i = low;i<=high;i++){
            if(i%3==a&&i%5==b&&i%7==c){
                printf("%d\n",i);
                flg = 1;
            }
        }
        if(!flg)
            printf("No answer\n");
    }
}