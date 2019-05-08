#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int size=300005;
vector vec[size];
int fa[size];
bool vis[size];
int fi,se;

int find(int x){
	int r=x,t;
	while(r!=fa[r])r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

void uni(int a,int b){
	int x=find(a),y=find(b);
	if(x!=y)fa[y]=x;
}

void LCA(int par){
	int i;
	for(i=0;i<vec[par].size();i++){
		LCA(vec[par][i]);
		uni(par,vec[par][i]);
	}
	vis[par]=1;
	if(par==fi&&vis[se]==1){
		
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			vec[i].clear();
			fa[i]=i;
		}
		for(i=1;i<=n;i++){
			int f,t;
			scanf("%d%d",&f,&t);
			vec[f].push_back(t);
		}
		int q;
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			scanf("%d%d",&fi,&se);
			LCA(1);
		}
	}
	return 0;
}
