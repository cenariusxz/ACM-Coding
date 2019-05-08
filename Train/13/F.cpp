#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

const int maxn=5e4+5;

struct seg{
	int a,b,l;
	bool operator < (const seg x)const{
		return l<x.l;
	}
}s[maxn];

int l[10005],r[10005];
int fa[505];
vector<int>v;

void init(){
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=1;i<=500;++i)fa[i]=i;
	v.clear();
}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=m;++i)scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].l);
		sort(s+1,s+m+1);
		r[s[2].l]=l[s[1].l]=1;
		for(int i=2;i<=m;++i){
			if(s[i].l==s[i-1].l)r[s[i].l]=i;
			else r[s[i].l]=l[s[i].l]=i;
		}
		for(int i=1;i<=m;++i){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				fa[x]=y;
				v.push_back(i);
			}
		}
		int cnt=0,ans=0;
		for(int i=0;i<v.size();++i){
			for(int j=1;j<=n;++j)fa[j]=j;
			for(int j=0;j<v.size();++j){
				if(j!=i){
					int x=find(s[v[j]].a),y=find(s[v[j]].b);
					fa[x]=y;
				}
			}
			bool f=1;
			for(int j=l[s[v[i]].l];j<=r[s[v[i]].l];++j){
				if(j!=v[i]){
					int x=find(s[j].a),y=find(s[j].b);
					if(fa[x]!=y){
						f=0;
						break;
					}
				}
			}
			if(f){
				cnt++;
				ans+=s[v[i]].l;
			}
		}
		printf("%d %d\n",cnt,ans);
	}
	return 0;
}
