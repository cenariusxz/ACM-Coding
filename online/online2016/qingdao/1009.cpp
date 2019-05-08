#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

ll dp[maxn][2],Dpl[maxn][2],Dpr[maxn][2],Dpf[maxn][2];
ll ans[maxn];
int a[maxn],head[maxn],point[maxn<<1],val[maxn<<1],nxt[maxn<<1];
int n,size;
int fa[maxn];

//0 buhui 1 hui

inline ll max(ll a,ll b){return a>b?a:b;}

inline void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

inline void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void Dfs(int s,int f){
	fa[s]=f;
	dp[s][0]=dp[s][1]=a[s];
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==f)continue;
		Dfs(j,s);
		ll tmp0=dp[j][0]-val[i];
		ll tmp1=dp[j][1]-2*val[i];
		dp[s][0]=max(dp[s][0],max(dp[s][1]+tmp0,dp[s][0]+tmp1));
		dp[s][1]=max(dp[s][1],dp[s][1]+tmp1);
	}
}

void check(int s,int id,int v){
	if(s==1){
		Dpf[s][0]=Dpf[s][1]=0;
	}
	else{
		Dpf[s][0]=max(0,-v+a[fa[s]]+max(Dpl[id-1][0]+Dpr[id+1][1]+Dpf[fa[s]][1],max(Dpl[id-1][1]+Dpr[id+1][0]+Dpf[fa[s]][1],Dpl[id-1][1]+Dpr[id+1][1]+Dpf[fa[s]][0])));
		Dpf[s][1]=max(0,-2*v+a[fa[s]]+Dpl[id-1][1]+Dpr[id+1][1]+Dpf[fa[s]][1]);
	}
	ans[s]=max(dp[s][0],dp[s][1]);
	ans[s]=max(ans[s],dp[s][1]+Dpf[s][0]);
	ans[s]=max(ans[s],Dpf[s][1]+dp[s][0]);
}

void dfs(int s,int id,int v){
	int que[maxn][2];
	int cnt=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==fa[s])continue;
		que[++cnt][0]=j;
		que[cnt][1]=val[i];
	}
	Dpl[0][0]=Dpl[0][1]=0;
	Dpr[cnt+1][0]=Dpr[cnt+1][1]=0;
	for(int i=1;i<=cnt;++i){
		Dpl[i][0]=max(Dpl[i-1][0],max(Dpl[i-1][1]-que[i][1]+dp[que[i][0]][0],Dpl[i-1][0]-2*que[i][1]+dp[que[i][0]][1]));
		Dpl[i][1]=max(Dpl[i-1][1],Dpl[i-1][1]-2*que[i][1]+dp[que[i][0]][1]);
	}
	for(int i=cnt;i>=1;--i){
		Dpr[i][0]=max(Dpr[i+1][0],max(Dpr[i+1][1]-que[i][1]+dp[que[i][0]][0],Dpr[i+1][0]-2*que[i][1]+dp[que[i][0]][1]));
		Dpr[i][1]=max(Dpr[i+1][1],Dpr[i+1][1]-2*que[i][1]+dp[que[i][0]][1]);
	}
	for(int i=1;i<=cnt;++i){
		check(que[i][0],i,que[i][1]);
	}
	for(int i=1;i<=cnt;++i){
		dfs(que[i][0],i,que[i][1]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<n;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		Dfs(1,-1);
		check(1,0,0);
		dfs(1,0,0);
		printf("Case #%d:\n",q);
		for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
		//	for(int i=1;i<=n;++i)printf("%lld %lld\n",dp[i][0],dp[i][1]);	
	}
	return 0;
}
