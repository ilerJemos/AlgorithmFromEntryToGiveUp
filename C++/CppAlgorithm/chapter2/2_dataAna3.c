//多组数据

#include<stdio.h>
#define LOCAL
const int INF=1000;

int main(){

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int x,n=0;
    int min = INF,max = -INF;
    int s = 0;
    int kase = 0;
    
    while(scanf("%d",&n)==1 && n){
        s = 0;
        min = INF;
        max = -INF;
        for(int i = 1;i<=n;i++){
            scanf("%d",&x);
            s+=x;
            if (x<min) min = x;
            if (x>max) max = x;
        }
        if (kase) printf("\n");
        printf("Case %d: %d %d %.3f\n",++kase,min,max,(double)s/n);
    }
}