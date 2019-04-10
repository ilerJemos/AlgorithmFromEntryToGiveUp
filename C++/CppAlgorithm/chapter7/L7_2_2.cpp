//生成可重复集的排列

#include<iostream>
#include<algorithm>
#include<string>

//using namespace std;

void print_permutation(int n,std::string& p,std::string& a,int cur){
    if(cur==n){
        for(int i = 0;i<n;i++){
            std::cout<<a[i]<<" ";
        }
        std::cout<<std::endl;
    }
    for(int i = 0;i<n;i++)if(!i||(p[i]!=p[i-1])){
        int c1 = 0,c2=0;
        for(int j = 0;j<n;j++)
            if(p[j]==p[i]) c1++;
        for(int j = 0;j<cur;j++)
            if(a[j]==p[i]) c2++;
        if(c2<c1){ 
            a[cur]=p[i];
            print_permutation(n,p,a,cur+1);
        }
    }
}

int main(){
    int n;
    std::string p,a;
    std::cin>>p;
    n =p.length();
    //std::cout<<n<<std::endl;
    std::sort(p.begin(),p.end());
    print_permutation(n,p,a,0);

    return 0;
}