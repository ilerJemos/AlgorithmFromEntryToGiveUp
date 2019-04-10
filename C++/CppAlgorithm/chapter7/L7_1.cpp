#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int n ;
    cin>>n;
    int fghij=1234;
    int abcde;
    char s[100];
    for(;;fghij++){ 
        abcde = fghij*n;
        sprintf(s,"%05d%05d",abcde,fghij);
        //cout<<s<<endl;
        //cout<<strlen(s)<<endl;
        if(strlen(s)>10) break;
        sort(s,s+10);
        //cout<<s<<endl;
        //break;
        bool ok = true;
        for(int i = 0;i<10;i++){
            if(s[i]!='0'+i){
                ok = false;
                break;
            }
        }
        if (ok){
            printf("%05d/%05d = %d\n",abcde,fghij,n);
        }

    }
    return 0;
}