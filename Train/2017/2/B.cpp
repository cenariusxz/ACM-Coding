#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int mod=1e9+7;

int a[maxn],b[maxn];
ll val[maxn],ans;

int head[maxn],nxt[maxn],point[maxn],size;
int id[maxn];

void init(){
	size=0;
	ans=0;
	memset(head,-1,sizeof(head));
	memset(id,0,sizeof(id));
	memset(val,0,sizeof(val));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

ll dfs(int s){
	if(val[s])return val[s];
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		val[s]+=dfs(j);
		if(val[s]>=mod)val[s]-=mod;
	}
	ans+=val[s]*a[s]%mod;
	if(ans>=mod)ans-=mod;
	val[s]+=b[s];
	if(val[s]>=mod)val[s]-=mod;
	return val[s];
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a[i],&b[i]);
		}
		for(int i=1;i<=m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		for(int i=1;i<=n;++i){
			if(id[i]==0)dfs(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
