#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=20005;
const int maxp=5005;
const int maxm=1e5+5;

struct seg{
	int a,b,v;
	bool operator < (const seg a)const{
		return v<a.v;
	}
}s[maxm];

struct peo{
	int num,v,cnt;
	bool operator < (const peo a)const{
		return v<a.v;
	}
}p[maxp];

int n,m;
int fa[maxn],num[maxn],ans[maxp];
int nnum[100010];

void init(){
	for(int i=0;i<=n;i++){fa[i]=i;num[i]=1;}
	memset(ans,0,sizeof(ans));
	memset(p,0,sizeof(p));
}

int find(int x){
	int r=x,t;
	while(fa[r]!=r)r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i=1;i<=m;++i)scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
		int maxx=0;
		for(int i=1;i<=k;++i){
			scanf("%d",&p[i].v);
			p[i].num=i;
			if(p[i].v>maxx)maxx=p[i].v;
		}
		sort(s+1,s+m+1);
		int pos=1;
		int aans=0;
		memset(nnum,0,sizeof(nnum));
		for(int i=1;i<=m;++i){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				int nx=num[x],ny=num[y];
				aans+=nx*ny;
				nnum[s[i].v]+=nx*ny*2;
				fa[x]=y;
				num[y]+=num[x];
			}
		}
		for(int i=1;i<=maxx;++i)nnum[i]+=nnum[i-1];
		for(int i=1;i<=k;++i)printf("%d\n",nnum[p[i].v]);
	}
	return 0;
}
