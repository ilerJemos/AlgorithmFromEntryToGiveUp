//set 集合 
//Andy's First Dictinary
//安迪的第一个字典 
//Adventures in Disneyland
//Two blondes were goging to Disneyland when the came to a fork in the road. the sign read:"Disneyland Left."
//So they went home
#include<iostream>
#include<string>
#include<set>
#include<sstream> 
using namespace std;

set<string> dict;

int main(){
	freopen("data.in","rb",stdin); 
	freopen("data.out","wb",stdout);
	string s,buf;
	while(cin >>s){
		for(int i=0;i<s.length();i++){
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' ';
		}
		stringstream ss(s);
		while(ss>>buf)
			dict.insert(buf);
	}
	for(set<string>::iterator it = dict.begin();it!=dict.end();it++)
		cout<<*it<<"\n";
	return 0;
}
