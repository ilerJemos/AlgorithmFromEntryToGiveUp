#include<iostream>
#include<string.h>
using namespace std;
#define maxn 20
int a[maxn][maxn];
int maingbihi(){

    
    memset(a,0,sizeof(a));
    int s,fir;
    //cin>>s;
    s = 10;
    int x = -1,y = s-1;
    fir = 1;

    while(fir<=s*s){
        while((x+1<s)&&(a[x+1][y]==0)) a[++x][y]=fir++;
        
        while((y-1>=0)&&(a[x][y-1]==0)) a[x][--y]=fir++;

        while((x-1>=0)&&(a[x-1][y]==0)) a[--x][y]=fir++;

        while((y+1<s)&&(a[x][y+1]==0)) a[x][++y]=fir++;
    }

    for(int i =0;i<s;i++){
        for(int j = 0;j<s;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;

}