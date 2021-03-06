#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

void find_blocK(int a,int &p,int &h){
    for(p = 0;p<n;p++){
        for(h = 0;h<pile[p].size();h++){
            if(pile[p][h]==a) return;
        }
    }
}
void clear_above(int p,int h){
    for(int i = h+1;i<pile[p].size();i++){
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}
void pile_onto(int p,int h,int p2){
    for(int i = h;i<pile[p].size();i++){
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}
void print(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<pile[i].size();j++)
            printf("%d ",pile[i][j]);
        printf("\n");
    }
}
int main(){
    int a,b;
    cin >> n;
    for(int i = 0;i<n;i++) pile[i].push_back(i);
    string s1,s2;
    int pa,pb,ha,hb;

    while(cin>>s1>>a>>s2>>b){
        find_blocK(a,pa,ha);
        find_blocK(b,pb,hb);
        //cout<<pa<<ha<<pb<<hb<<endl;
        if (pa==pb) continue;
        if(s1=="move") clear_above(pa,ha);
        if(s2=="onto") clear_above(pb,hb);
        pile_onto(pa,ha,pb);
    }
    print();

    return 0;
}