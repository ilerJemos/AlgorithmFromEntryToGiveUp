//map
//Ananagrams ∑¥∆¨”Ô
// ladder came tape soon leader acme RIDE lone Dreis peat 
// ScAlE orb eye Rides dealer NotE derail LaceS drIed
// noel dire Disk mace dries
// #
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;

string repr(const string& s){
	string ans = s;
	for(int i=0;i<s.length();i++)
		if(isalpha(ans[i]))
			ans[i]=tolower(ans[i]);
		else
			ans[i]=' ';
		
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	freopen("data.in","rb",stdin);
	freopen("data.out","wb",stdout);
	int n=0;
	string s;
	while(cin>>s){
		if(s[0]=='#') break;
		words.push_back(s);
		string r = repr(s);
		if(!cnt.count(r)) cnt[r]=0;
		cnt[r]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++){
		if(cnt[repr(words[i])]==1)
			ans.push_back(words[i]);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
	
	return 0;
}
