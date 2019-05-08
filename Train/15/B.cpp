#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct seg{
	int a,b,v;
	bool operator <(const seg x)const{
		return v<x.v;
	}
}s[2000000];

int fa[1005];

void init(){
	for(int i=0;i<=1000;++i)fa[i]=i;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		init();
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1;i<=m;++i){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
			sum+=s[i].v;
		}
		sort(s+1,s+m+1);
		for(int i=1;i<=m;++i){
			int X=find(s[i].a),Y=find(s[i].b);
			if(X!=Y){
				fa[X]=Y;
				sum-=s[i].v;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
