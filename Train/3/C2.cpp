#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int head[maxn],point[maxn],nxt[maxn],size;
int col[maxn],fa[maxn];
int dp[2][2][maxn];
// 0 可监督别人     1 不可监督别人
// 0 需要人监督     1 不需要人监督
int n,k;

void init(){
	memset(head,-1,sizeof(head));
	memset(col,0,sizeof(col));
	size=0;
	memset(dp,-1,sizeof(dp));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int Max(int a){
	return max(dp[0][0][a],max(dp[0][1][a],max(dp[1][0][a],dp[1][1][a])));
}

void dfs(int s){
	if(col[s]==0){
		dp[0][1][s]=0;
		dp[0][0][s]=dp[1][0][s]=dp[1][1][s]=-1;
	}
	else{
		dp[0][0][s]=0;
		dp[0][1][s]=dp[1][0][s]=dp[1][1][s]=-1;
	}
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		dfs(j);
		int m=Max(j);
		int add=-1;
		if(col[s]==0){
			//1 1
			if(dp[1][1][s]>=0){
				dp[1][1][s]+=m;
			}
			add=max(dp[0][0][j],dp[1][0][j]);	//需要被监督
			if(add>=0&&dp[0][1][s]>=0)dp[1][1][s]=max(dp[1][1][s],dp[0][1][s]+add+1);

			//0 1
			dp[0][1][s]+=m;

		}
		else{
			//1 1
			if(dp[1][1][s]>=0){
				dp[1][1][s]+=m;
			}
			add=max(dp[0][0][j],dp[0][1][j]);
			if(add>=0&&dp[1][0][s]>=0)dp[1][1][s]=max(dp[1][1][s],dp[1][0][s]+add+1);
			add=max(dp[0][0][j],dp[1][0][j]);
			if(add>=0&&dp[0][1][s]>=0)dp[1][1][s]=max(dp[1][1][s],dp[0][1][s]+add+1);

			//0 1
			if(dp[0][1][s]>=0){
				dp[0][1][s]+=m;
			}
			add=max(dp[0][0][j],dp[0][1][j]);	//可监督别人
			if(add>=0&&dp[0][0][s]>=0)dp[0][1][s]=max(dp[0][1][s],dp[0][0][s]+add+1);

			//1 0
			if(dp[1][0][s]>=0){
				dp[1][0][s]+=m;
			}
			add=max(dp[0][0][j],dp[1][0][j]);
			if(add>=0&&dp[0][0][s]>=0)dp[1][0][s]=max(dp[1][0][s],dp[0][0][s]+add+1);

			//0 0
			dp[0][0][s]+=m;

		}
	}
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==0&&k==0)break;
		init();
		for(int i=1;i<=n;++i){
			scanf("%d",&fa[i]);
			add(fa[i],i);
		}
		for(int i=1;i<=k;++i){
			int a;
			scanf("%d",&a);
			col[a]=1;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!fa[i]){
				dfs(i);
				ans+=max(dp[0][0][i],max(dp[0][1][i],max(dp[1][0][i],dp[1][1][i])));
			}
		}
//		for(int i=1;i<=n;++i)printf("%d: %d %d %d %d\n",i,dp[0][0][i],dp[0][1][i],dp[1][0][i],dp[1][1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
