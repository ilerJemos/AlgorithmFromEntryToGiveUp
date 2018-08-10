//ÉßÐÎÌîÊý
#include<stdio.h> 
#include<string.h>

#define maxn 20

int a[maxn][maxn];

int main(){
	FILE *fin,*fout;
	fin=fopen("data.in","rb");
	fout=fopen("data.out","wb");
	
	int n,x,y,fir;
	fscanf(fin,"%d",&n);
	memset(a,0,sizeof(a)); 
	fir=a[x=0][y=n-1]=1;
	//printf("%d%d",x,y); 
	while(fir<n*n){
		while(x+1<n&&!a[x+1][y]) a[++x][y] = ++fir;
		while(y-1>=0&&!a[x][y-1]) a[x][--y] = ++fir;
		while(x-1>=0&&!a[x-1][y]) a[--x][y] = ++fir;
		while(y+1<n&&!a[x][y+1]) a[x][++y] = ++fir;
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			fprintf(fout,"%4d",a[x][y]);
		}
		fprintf(fout,"\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
