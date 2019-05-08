#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=(1<<(24))+5;
const int INF=0x3f3f3f3f;

int dp[maxn];
int nxt[maxn];

int G[50][50];
int x[50],y[50];
int dis[50];

int n;

inline int get(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

int dfs(int sta){
	if(dp[sta]!=INF)return dp[sta];
	for(int i=0;i<n;++i){
		if(sta&(1<<i)){
			int tmp2=dfs(sta-(1<<i))+dis[i];
			if(tmp2<dp[sta]){
				dp[sta]=tmp2;
				nxt[sta]=sta-(1<<i);
			}
			for(int j=i+1;j<n;++j){
				if(sta&(1<<j)){
					int tmp=dfs(sta-(1<<i)-(1<<j))+G[i][j];
					if(tmp<dp[sta]){
						dp[sta]=tmp;
						nxt[sta]=sta-(1<<i)-(1<<j);
					}
				}
			}
			break;
		}
	}
	return dp[sta];
}

int main(){
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&x[0],&y[0]);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		dis[i-1]=2*get(0,i);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			G[i-1][j-1]=G[j-1][i-1]=get(0,i)+get(0,j)+get(i,j);
		}
	}
	dp[0]=0;
	for(int i=0;i<n;++i){
		dp[1<<i]=dis[i];
		nxt[1<<i]=0;
	}
	int ans=dfs((1<<n)-1);
	printf("%d\n",ans);
	int tmp=(1<<n)-1;
	printf("0");
	while(tmp){
		int tmp2=nxt[tmp];
		for(int i=0;i<n;++i){
			if((tmp&(1<<i))&&!(tmp2&(1<<i)))printf(" %d",i+1);
		}
		printf(" 0");
		tmp=tmp2;
	}
	printf("\n");
	return 0;
}
