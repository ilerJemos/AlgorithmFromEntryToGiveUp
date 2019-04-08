//竖式问题

#include<stdio.h>
#include<string.h>



int main(){
    int count = 0;
    char s[20],buf[99];
    scanf("%s",s);

    for(int abc = 100;abc<=999;abc++){
        for(int de = 10;de<100;de++){

            int x = abc*(de%10);
            int y = abc*(de/10);
            int z = abc*de;

            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int ok = 1;
            for(int i =0;i<strlen(buf);i++){
                if(strchr(s,buf[i])==NULL)
                    ok = 0;
            }


            if(ok){
                
                printf("<%d>\n",++count);

                printf("%5d\nX%4d\n-----\n%5d\n%d\n-----\n%d\n\n",abc,de,x,y,z);

            }
        }
    }
    printf("The number of solutions = %d\n",count);
}