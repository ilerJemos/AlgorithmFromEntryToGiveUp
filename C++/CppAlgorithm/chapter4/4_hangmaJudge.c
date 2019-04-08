//刽子手游戏
#include<stdio.h>
#include<string.h>

#define maxn 100

char s[maxn],s2[maxn];
int chance,left;
int win,lose;
void guess(char ch){
    char* d;
    d=strchr(s,ch);
    if(d==NULL){ 
        chance--;
        if(chance ==0) lose =1;
    }
    else{
        
        for(d;d!=NULL;d=strchr(s,ch)){
            *d=' ';
            left--;
        }
        if(left==0) win = 1;
        
    }
    

}

int main(){
    freopen ("../input.txt","r",stdin);
    int rnd = 0;
    while(scanf("%d%s%s",&rnd,s,s2)==3&&rnd!=-1){
        printf("Round %d\n",rnd);
        chance = 7;
        left = strlen(s);
        win =0;
        lose = 0;
        for(int i = 0;i<strlen(s2);i++){
            guess(s2[i]);
            if(win||lose)
                break;
        }
        if (win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You checked out.\n");
    }
    
    return 0;
}