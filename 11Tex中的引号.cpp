//TeX中的引号
//Tex Quotes,UVa 272
//在使用getchat ,fgetc时，应避免写出和操作系统相关的程序 
#include<stdio.h> 
#include<string.h>

int main(){
	FILE *fin,*fout;
	fin = fopen("data.in","rb");
	fout = fopen("data.out","wb");
	
	int c,q=1;
	while((c=fgetc(fin))!=EOF) {
		if(c=='"'){
			fprintf(fout,"%s",q? "``":"^^");
			q=!q;
		}
		else
			fprintf(fout,"%c",c);
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
