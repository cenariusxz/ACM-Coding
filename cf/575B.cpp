#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=1e6+5;
const int mod=1e9+7;
const int MAX_LOG=18;

ll a[maxm];
int dp[maxn][2];
int head[maxn],point[maxm*2],nxt[maxm*2],val[maxm*2],size;
int fa[MAX_LOG][maxn],dep[maxn];
int N;

void add(int a,int b,int f){
	point[size]=b;
	nxt[size]=head[a];
	val[size]=f;
	head[a]=size++;
}

void Dfs(int p,int pre,int d){
	fa[0][p] = pre;
	dep[p] = d;
	for(int i = head[p]; ~i; i = nxt[i]){
		int v = point[i];
		if(v == pre) continue;
		Dfs(v,p,d + 1);
	}
}

void Pre(){
	a[0]=1;
	for(int i=1;i<maxm;++i)a[i]=a[i-1]*2%mod;
	Dfs(1,-1,0);
	for(int k = 0; k + 1 < MAX_LOG; ++k){
		for(int v = 1; v <= N; ++v){
			if(fa[k][v] < 0) fa[k + 1][v] = -1;
			else fa[k + 1][v] = fa[k][fa[k][v]];
		}
	}
}

int Lca(int u,int v){
	if(dep[u] > dep[v]) swap(u,v);
	for(int k = MAX_LOG - 1; k >= 0; --k){
		if((dep[v] - dep[u]) & (1 << k))
			v = fa[k][v];
	}
	if(u == v) return u; //u为v的根
	for(int k = MAX_LOG - 1; k >= 0; --k){
		if(fa[k][u] != fa[k][v]){
			u = fa[k][u];
			v = fa[k][v];
		}
	}
	return fa[0][u]; //u离lca只差一步
}

void dfs(int s,int pre){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==pre)continue;
		dfs(j,s);
		dp[s][0]+=dp[j][0];
		dp[s][1]+=dp[j][1];
	}
}

int main(){
	memset(head,-1,sizeof(head));
	size=0;
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c==0){
			add(a,b,1);
			add(b,a,1);
		}
		else{
			add(a,b,1);
			add(b,a,2);
		}
	}
	Pre();
	int pre=1;
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		int a;
		scanf("%d",&a);
		int lca=Lca(a,pre);
		dp[lca][0]--;
		dp[lca][1]--;
		dp[pre][0]++;
		dp[a][1]++;
		pre=a;
	}
//	for(int i=1;i<=N;++i){
//		printf("%d:%d %d\n",i,dp[i][0],dp[i][1]);
//	}
	dfs(1,-1);
//	for(int i=1;i<=N;++i){
//		printf("%d:%d %d\n",i,dp[i][0],dp[i][1]);
//	}
	ll ans=0;
	for(int i=1;i<=N;++i){
		for(int j=head[i];~j;j=nxt[j]){
			if(val[j]==1)continue;
			int k=point[j];
		//	printf("%d %d\n",i,k);
			if(dep[i]>dep[k]){
				ans+=a[dp[i][0]]-1;
			}
			else{
				ans+=a[dp[k][1]]-1;
			}
		}
	}
	printf("%I64d\n",ans%mod);
	return 0;
}
