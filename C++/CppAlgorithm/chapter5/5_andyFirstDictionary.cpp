#include<iostream>
#include<set>
#include<sstream>
#include<string>

#include<fstream>

using namespace std;

set<string> dict;

int main(){
    //ifstream fin;
    //ofstream fout;
    fstream file;
    file.open("../input.txt");
    cin.rdbuf(file.rdbuf());
    string s,buf;
    while(cin>>s){
        for(int i = 0;i<s.length();i++){
            if(isalpha(s[i]))
                s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf) dict.insert(buf);
    }
    for(set<string>::iterator it = dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;

    file.close();
    return 0;
}