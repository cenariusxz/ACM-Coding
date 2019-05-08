#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct cell{
	int d,t;
	bool operator <(const cell a)const{
		return t>a.t;
	}
}c[100005];


int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&c[i].d,&c[i].t);
		sort(c+1,c+n+1);
		int ans=0,pre=0;
		for(int i=1;i<=n;++i){
			if(pre+c[i].t+c[i].d>ans)ans=pre+c[i].t+c[i].d;
			pre+=c[i].d;
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
