//子序列的和

#include<stdio.h>
#include<math.h>

#define LOCAL

int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    int m,n;
    int kase = 0;
    double ans;
    while(scanf("%d%d",&m,&n)==2&&(m!=0&&n!=0)){
        //printf("%d %d\n",m,n);
        while(m<=n){     
            printf("%d ",m); 
            ans+=1.0/pow(m,2);
            m++;
        }
        printf("Case %d: %.5lf\n",++kase,ans);
    }
    return 0;
}