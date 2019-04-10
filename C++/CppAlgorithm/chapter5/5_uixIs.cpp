#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

const int maxcol = 60;

//输出s，长度不足len时用extra补足
void print(const string& s,int len,char extra){
    cout<<s;
    for(int i = 0;i<len-s.length();i++){
        cout<<extra;
    }
}

int main(){
    //输入重定向
    fstream file;
    file.open("../input.txt");
    cin.rdbuf(file.rdbuf());

    int n,M=0;
    vector<string> filename;
    while(cin>>n){
        string s;
        for(int i = 0;i<n;i++){
            cin>>s;
            filename.push_back(s);
            M = max(M,(int)s.length());
        }
        //计算列数和行数
        int cols = (maxcol-M)/(M+2)+1;
        int rows = (n-1)/cols+1;
         
        sort(filename.begin(),filename.end());
        
        print("",60,'-');
        cout<<"\n";
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                int idx = j*rows+i;
                if(idx<n) print(filename[idx],j==cols-1?M:M+2,' ');
            }
            cout<<endl;
        }
    }
    return 0;
}