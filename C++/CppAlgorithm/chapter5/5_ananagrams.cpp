#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

vector<string> words;
map<string,int> cnt;

string repr(const string &s){
    string ans=s;
    for(int i = 0;i<s.length();i++){
        ans[i]=tolower(s[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    fstream file;
    file.open("../input.txt");
    cin.rdbuf(file.rdbuf());

    string s;
    while(cin>>s){
        if(s=="#") break;
        words.push_back(s);
        string r = repr(s);
        if(!cnt.count(r)) cnt[r]=0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i = 0;i<words.size();i++){
        if(cnt[repr(words[i])]==1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}