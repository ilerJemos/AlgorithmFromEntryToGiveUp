//Where is the marble
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;//C++中推荐使用const 而不是#define 
int main(){
	FILE * fin;
	fin = fopen("data.in","rb");
	int n,q,x,a[maxn],kase=0;
	while(fscanf(fin,"%d%d",&n,&q)==2&&n){
		printf("CASE# %d:\n",++kase);
		for(int i=0;i<n;i++) fscanf(fin,"%d",&a[i]);
		sort(a,a+n);//排序
		while(q--){
			fscanf(fin,"%d",&x);
			int p = lower_bound(a,a+n,x)-a;//在已排序的数组中寻找x
			if(a[p]==x) printf("%d found at %d\n",x,p+1);
			else printf("%d not found\n",x);
		} 
	}
	
	fclose(fin);
	return 0;
} 
