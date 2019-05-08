#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using  namespace std;
typedef long long ll;

const ll INF=1ll<<60;
const int maxn=2e5+5;

int head[maxn],point[maxn],nxt[maxn],val[maxn],size;
ll maxx[maxn],sum[maxn];
ll ans=-INF;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s,int fa){
//	printf("aaa: %d\n",s);
	sum[s]=val[s];
	maxx[s]=-INF;
	ll M1=-INF,M2=-INF;
	int cnt=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==fa)continue;
		cnt++;
		dfs(j,s);
		if(maxx[j]>maxx[s])maxx[s]=maxx[j];
		sum[s]+=sum[j];
		if(maxx[j]>M1){
			M2=M1;
			M1=maxx[j];
		}
		else if(maxx[j]>M2){
			M2=maxx[j];
		}
	}
	if(cnt>=2){
		if(M1+M2>ans)ans=M1+M2;
	}
	if(sum[s]>maxx[s])maxx[s]=sum[s];
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,-1);
	if(ans==-INF)printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0;
}
