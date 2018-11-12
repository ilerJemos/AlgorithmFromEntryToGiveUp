//救济金发放
//The Dole Queue 
#include<stdio.h>

#define maxn 25

int a[maxn],n;

int go(int p,int d,int t){
	while(t--){
		do{
			p =(p+d+n-1)%n +1;//转圈，并保证获得的数字有意义 
		}while(a[p]==0);//走到下一个非零的数字 
	}
	return p;
}

int mai32n(){
	FILE *fin,*fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb") ;
	
	int k,m;
	while(fscanf(fin,"%d%d%d",&n,&k,&m)==3&&n){
		for(int i=1;i<=n;i++) a[i]=i;
		int left=n;
		int p1=n,p2=1;//从要数的位置，回退一位 
		while(left){	
			p1=go(p1,1,k);
			p2=go(p2,-1,m);
			printf("%3d",p1);left--;
			if(p1!=p2){
				printf("%3d",p2);
				left--;
			}
			a[p1]=a[p2]=0;
			if(left) printf(",");
		}
		printf("\n") ;
	}
	
	
	
	fclose(fin);
	fclose(fout);
	return 0;
}
