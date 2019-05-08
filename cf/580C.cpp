#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=2e5+5;
const int INF=0x3f3f3f3f;

int head[maxn],nxt[maxm],point[maxm],size;
int vis[maxn],v[maxn];
int dp[maxn];
int n,m;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int s,int num){
	if(num>m)return 0;
	vis[s]=1;
	int ans=0;
	bool f=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]){
			f=1;
			if(v[j])ans+=dfs(j,num+1);
			else ans+=dfs(j,0);
		}
	}
	if(f)return ans;
	else return 1;
}

int main(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	printf("%d\n",dfs(1,v[1]));
	return 0;
}
