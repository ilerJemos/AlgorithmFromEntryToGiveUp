//输入输出重定向
//简单自然，不能同时读写文件和标准输入输出
 
//使用 fopen
//稍显繁琐，但更加灵活， 可通过赋值 “fin=stdin,fout=stdout” 改成读写标准输入输出 

//#define LOCAL 
#include<stdio.h> 
#define INF 1000000000
int main(){
//	#ifdef LOCAL
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
//	#endif
//	
//	int x,n=0,min=INF,max=-INF,s=0;
//	while(scanf("%d",&x)==1){
//		s+=x;
//		if(x<min) min=x;
//		if(x>max) max=x;
//		n++;
//	}
//printf("%d %d %.3f\n",min,max,(double)s/n);
	FILE *fin,*fout;
	fin=fopen("data.in","rb");
	fout =fopen("data.out","wb");
	
	int x,n=0,min=INF,max=-INF,s=0;
	while(fscanf(fin,"%d",&x)==1){
		s+=x;
		if(x<min) min=x;
		if(x>max) max=x;
		n++;
	}
	fprintf(fout,"%d %d %.3f\n",min,max,(double)s/n);
	fclose(fin);
	fclose(fout);
	return 0;
}
