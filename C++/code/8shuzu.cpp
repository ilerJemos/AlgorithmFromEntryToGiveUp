//�Ƚϴ������Ӧ��������main���������棬�����������޷�����
//�������� 
#include<stdio.h> 
#include<string.h>
//���鸳ֵ memcpy(a,b,sizeof(b)) include<string.h> 
//�����ʼ�� memset(a,0,sizeof(a)) 

#define maxn 1010
int a[maxn];
int main(){
	int n,k,first=1;
	FILE *fin,*fout;
	fin=fopen("data.in","rb");
	fout = fopen("data.out","wb");
	
	memset(a,0,sizeof(a));
	fscanf(fin,"%d%d",&n,&k) ;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j%i==0)
				a[j]=!a[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(first)
				first=0;
			else fprintf(fout," ");
			fprintf(fout,"%d",i);
		}
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
