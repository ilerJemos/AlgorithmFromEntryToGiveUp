//�ȼý𷢷�
//The Dole Queue 
#include<stdio.h>

#define maxn 25

int a[maxn],n;

int go(int p,int d,int t){
	while(t--){
		do{
			p =(p+d+n-1)%n +1;//תȦ������֤��õ����������� 
		}while(a[p]==0);//�ߵ���һ����������� 
	}
	return p;
}

int main(){
	FILE *fin,*fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb") ;
	
	int k,m;
	while(fscanf(fin,"%d%d%d",&n,&k,&m)==3&&n){
		for(int i=1;i<=n;i++) a[i]=i;
		int left=n;
		int p1=n,p2=1;//��Ҫ����λ�ã�����һλ 
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
