//The blocks Problem
//ľ������ 
//10
//move 9 onto 1
//move 8 over 1
//move 7 over 1
//move 6 over 1
//pile 8 over 6
//pile 8 over 5
//move 2 over 1
//move 4 over 9
//quit
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

//���ҷ������ڵ�λ�ã��������õķ�ʽ����
void find_block(int a,int& p,int& h){
	for(p=0;p<n;p++){
		for(h=0;h<pile[p].size();h++){
			if(pile[p][h]==a)
				return;
		}
	}
} 
//��p�Ѹ߶�Ϊh��ľ���Ϸ����е�ľ���ƻ�ԭλ
void clear_above(int p,int h){
	for(int i=1;i<pile[p].size();i++){
		int b = pile[p][i];
		pile[b].push_back(b);//ľ��b�Ż�ԭλ 
	}
	pile[p].resize(h+1);//ֻ����0~h��Ԫ�� 
} 

//�ѵ�p�Ѹ߶�Ϊh�����Ϸ���ľ�������ƶ���p2����
void pile_onto(int p,int h,int p2){
	for(int i=h;i<pile[p].size();i++)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
} 
//���
void print(){
	for(int i=0;i<n;i++){
		printf("%d: ",i);
		for(int j=0;j<pile[i].size();j++)
			printf(" %d",pile[i][j]);
		printf("\n");
	}
} 
int main(){
	int a,b;
	cin >>n;
	string s1,s2;
	for(int i=0;i<n;i++)
		pile[i].push_back(i);
	
	while((cin>>s1)&&(s1!="quit")){
		cin>>a>>s2>>b;
		int pa,pb,ha,hb;
		find_block(a,pa,ha);
		find_block(b,pb,hb);
		if(pa==pb) continue;
		if(s2=="onto") clear_above(pb,hb);
		if(s1=="move") clear_above(pa,ha);
		pile_onto(pa,ha,pb);
	}
	print();
	
	
	return 0;
}
