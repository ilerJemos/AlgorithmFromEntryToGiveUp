#include<stdio.h>
#include<string.h>

int main(){
    freopen("../input.txt","r",stdin);
    char c;
    int q = 1;
    while((c = getchar())!=EOF ){
        if(c=='"'){
            printf("%s",q?"``":"''");
        }
        else
            printf("%c",c);
    }
    return 0;
}