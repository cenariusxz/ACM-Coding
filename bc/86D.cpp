#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int maxn=55;
const int maxm=2505;

int head[maxn],point[maxm],nxt[maxm],size;
int v[maxn];
ll dp[55][55][55];
int vis[55][55][55];
int n,m,K,q;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void init(){
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	size=0;
}

ll dfs(int x,int y,int z){
	if(vis[x][y][z])return dp[x][y][z];
	ll sum=1;
	for(int i=head[x];~i;i=nxt[i]){
		int dx=point[i];
		for(int j=head[y];~j;j=nxt[j]){
			int dy=point[j];
			if(abs(v[dx]-v[dy])>K)continue;
			for(int k=head[z];~k;k=nxt[k]){
				int dz=point[k];
				if(abs(v[dx]-v[dz])>K||abs(v[dy]-v[dz]>K))continue;
		/*		if(dx>dy){int t=dx;dx=dy;dy=t;}
				if(dx>dz){int t=dx;dx=dz;dz=t;}
				if(dy>dz){int t=dy;dy=dz;dz=t;}*/
				sum+=dfs(dx,dy,dz);
				if(sum>=mod)sum-=mod;
			}
		}
	}
	vis[x][y][z]=1;
	return dp[x][y][z]=sum;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d%d%d",&n,&m,&K,&q);
		for(int i=1;i<=n;++i)scanf("%d",&v[i]);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		while(q--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
		/*	if(x>y){int t=x;x=y;y=t;}
			if(x>z){int t=x;x=z;z=t;}
			if(y>z){int t=y;y=z;z=t;}*/
			printf("%lld\n",dfs(x,y,z));
		}
	}
	return 0;
}
