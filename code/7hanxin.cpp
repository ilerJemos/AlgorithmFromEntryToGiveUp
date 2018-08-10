//º«ÐÅµã±ø
#include<stdio.h>
int main(){
	FILE *fin,*fout;
	fin=fopen("data.in","rb");
	fout=fopen("data.out","wb");
	
	int a,b,c;
	int count =0,flag=0;
	while(fscanf(fin,"%d%d%d",&a,&b,&c)==3){
		flag=0;
		for(int i=10;i<=100;i++){
			if((i%3==a)&&(i%5==b)&&(i%7==c)){
				count++;
				flag=1;
				fprintf(fout,"Case %d: %d\n",count,i);
			}
		}
		if(!flag){
			count++;
			fprintf(fout,"Case %d: No answer\n",count);
		}
		
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
