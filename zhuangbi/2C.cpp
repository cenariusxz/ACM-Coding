#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
const int maxp=1e5+5;
const int maxm=1e6+5;

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

void init(){
	for(int i=0;i<n;i++){fa[i]=i;num[i]=1;}
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
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=m;++i)scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;++i){
			scanf("%d",&p[i].v);
			p[i].num=i;
		}
		sort(s+1,s+m+1);
		sort(p+1,p+k+1);
		int pos=1;
		for(int i=1;i<=m;++i){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				int nx=num[x],ny=num[y];
				while(p[pos].v<=s[i].v&&pos<=k)pos++;
				pos--;
				if(pos==0)pos++;
				else p[pos].cnt+=nx*ny;
				fa[x]=y;
				num[y]+=num[x];
			}
		}
		ans[p[k].num]=p[k].cnt;
		for(int i=k-1;i>=1;--i){
			p[i].cnt+=p[i+1].cnt;
			ans[p[i].num]=p[i].cnt;
		}
		for(int i=1;i<=k;++i)printf("%d\n",ans[i]*2);
	}
	return 0;
}
