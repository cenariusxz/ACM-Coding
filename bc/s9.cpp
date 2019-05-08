#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxm=4000005;
const int INF=0x7fffffff;

int head[maxm],nxt[maxm],point[maxm],size,p[maxm];
bool vis[maxm];
bool v[maxm];
bool z[maxm],flag=0;

void add(int a,int b,int f){
	if(f){
		point[size]=b;
		nxt[size]=head[a];
		p[size]=size+1;
		head[a]=size++;
		point[size]=a;
		nxt[size]=head[b];
		p[size]=size-1;
		head[b]=size++;
	}
	else{
		point[size]=b;
		nxt[size]=head[a];
		p[size]=size;
		head[a]=size++;
	}
}

void dfs(int s){
	int i,j;
	z[s]=v[s]=1;
	for(i=head[s];~i;i=nxt[i]){
		if(vis[i])continue;
		int t=point[i];
		vis[i]=1;
		vis[p[i]]=1;
		if(z[t]){flag=1;return;}
		if(v[t])continue;
		dfs(t);
	}
	z[s]=0;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,m1,m2;
		scanf("%d%d%d",&n,&m1,&m2);
		int i,j;
		size=0;
		memset(head,-1,sizeof(head));
		for(i=1;i<=m1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,1);
		}
		for(i=1;i<=m2;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,0);
		}
		flag=0;
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		memset(z,0,sizeof(z));
		for(i=1;i<=n;i++){
			if(flag)break;
			if(!v[i]){
				dfs(i);
			}
		}
		if(!flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
