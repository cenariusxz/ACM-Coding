#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=4e5+5;
const int maxm=4e5+5;

int n,m;
int w[maxn];
int head[2][maxn],nxt[2][maxm],point[2][maxm],size[2];
int stx[maxn],low[maxn],sta[maxn],in[maxn],bcc[maxn];
int id[maxn];
int ind,top,block;
int tmp[maxn],cc;
int vis[maxn];
ll ans=0,sum1,sum;
ll mul[maxn];

void init(){
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	size[0]=size[1]=0;
	ans=0;
}

void add(int a,int b,int x){
	point[x][size[x]]=b;
	nxt[x][size[x]]=head[x][a];
	head[x][a]=size[x]++;
}

void tarj(int s,int fa){
	int v;
	low[s]=stx[s]=++ind;
	sta[top++]=s;
	in[s]=1;
	for(int i=head[0][s];~i;i=nxt[0][i]){
		v=point[0][i];
		if(v==fa)continue;
		if(!stx[v]){
			tarj(v,s);
			if(low[s]>low[v])low[s]=low[v];
			if(low[v]>=stx[s]){
				block++;
				w[block+n]=1;
				int vn;
				cc=0;
				add(s,block+n,1);
				add(block+n,s,1);
			//	printf("add:%d %d\n",s,block+n);
				id[s]++;
				id[block+n]++;
				do{
					vn=sta[--top];
					bcc[vn]=block;
					add(vn,block+n,1);
					add(block+n,vn,1);
			//		printf("add:%d %d\n",vn,block+n);
					id[vn]++;
					id[block+n]++;
					in[vn]=0;
					tmp[cc++]=vn;
				}while(vn!=v);
			}
		}
		else if(in[v]&&low[s]>stx[v])low[s]=stx[v];
	}
}

ll QP(ll a,ll n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

ll dfs3(int s,int fa){
	vis[s]=1;
	if(id[s]==1&&s<=n){
		ans=(ans+mul[s]*QP(w[s],mod-2)%mod*s%mod)%mod;
//		printf("%d %lld\n",s,mul[s]*QP(w[s],mod-2)%mod*s%mod);
	}
	ll M=w[s],S=0;
	for(int i=head[1][s];~i;i=nxt[1][i]){
		int j=point[1][i];
		if(j==fa)continue;
		ll tmp=dfs3(j,s);
		M=M*tmp%mod;
		S=(S+tmp)%mod;
	}
	if(id[s]>1&&s<=n){
		ll tmp;
		if(fa==-1)tmp=S*s%mod;
		else tmp=(S+mul[s]*QP(M,mod-2)%mod)%mod*s%mod;
//		printf("%d %lld\n",s,tmp);
		ans=(ans+tmp)%mod;
	}
	return M;
}

void solve(){
	memset(stx,0,sizeof(stx));
	memset(in,0,sizeof(in));
	ind=block=top=0;
	memset(id,0,sizeof(id));
	for(int i=1;i<=n;++i){
		if(!stx[i])tarj(i,-1);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			sum=sum1=0;
			dfs3(i,-1);
		}
	}
}

void dfs1(int s){
	vis[s]=1;
	sum+=s;
	sum1=sum1*w[s]%mod;
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(!vis[j])dfs1(j);
	}
}

void dfs2(int s){
	vis[s]=2;
	mul[s]=sum1;
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(vis[j]==1)dfs2(j);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&w[i]);
		ll ss=0;
		for(int i=1;i<=n;++i)ss+=i;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,0);
			add(b,a,0);
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]){
//				printf("%d\n",i);
				sum=0;
				sum1=1;
				dfs1(i);
				ans=(ans+(ss-sum)%mod*sum1%mod)%mod;
				dfs2(i);
			}
		}
//		printf("%lld\n",ans);
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
