//输入输入框架
//读写文件

#include <stdio.h>
#define INF 1000
int main(){
    FILE *fin,*fout;
    fin = fopen("input.txt","rb");
    fout = fopen("output.txt","wb");
    int x,n = 0,min = INF,max = -INF,s =0;
    while(fscanf(fin,"%d",&x)==1){
        s+=x;
        n++;
        if (x<min) min = x;
        if (x>max) max = x;
    }
    fprintf(fout,"%d %d %.3f\n",min,max,(double)s/n);
    fclose(fin);
    fclose(fout);
    return 0;
}