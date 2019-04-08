#include<stdio.h>
#include<string.h>

const int maxn = 20;

int main(){
    int n;
    scanf ("%d",&n);
    int a[maxn][maxn];
    memset(a,0,sizeof(a));
    int x= 0;
    int y = n-1;
    for(int i = 1;i<n*n;){
        while(x+1<n&&a[x+1][y]==0){a[x++][y]=i;i++;}
        while(y-1>=0&&a[x][y-1]==0){a[x][y--]=i;i++;}
        while(x-1>=0&&a[x-1][y]==0){ a[x--][y]=i;i++;}
        while(y+1<n&&a[x][y+1]==0){ a[x][y++]=i;i++;}
    }
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}