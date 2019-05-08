#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dp[1<<16][16];
int vis[1<<16][16];
int is[1<<16][16];
int n,m;

int head[105],point[100005],nxt[100005],val[100005],size;

void init(){
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

double Dp(int i,int j){
	if(vis[i][j])return dp[i][j];
	vis[i][j]=1;
	int que[16],cnt=0;
	for(int k=head[j];~k;k=nxt[k]){
		int t=point[k];
		if((i&(1<<t))==0&&is[i][t]){
			++cnt;
			que[cnt]=k;
		}
	}
	if(cnt==0)return dp[i][j]=5;
	dp[i][j]=0;
	for(int k=1;k<=cnt;++k){
		int t=point[que[k]];int v=val[que[k]];
		double tmp=Dp(i+(1<<t),t);
		dp[i][j]+=(tmp+v)/(cnt+1)+(tmp+v+5)/(cnt+1)/cnt;
	}
//	printf("%d %d %.6lf\n",i,j,dp[i][j]);
	return dp[i][j];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		memset(is,0,sizeof(is));
		for(int i=(1<<n)-1;i>=1;--i){
			for(int j=0;j<n;++j){
				if((i&(1<<j))==0){
					if(i+(1<<j)==(1<<n)-1){
						is[i][j]=1;
						printf("%d %d\n",i,j);
					}
					for(int p=head[j];~p;p=nxt[p]){
						int k=point[p];
						if((i&(1<<k))==0){
							if(is[i+(1<<j)][k]){
								is[i][j]=1;
								printf("%d %d\n",i,j);
							}
						}
					}

				}
			}
		}
		printf("Case %d: %.10lf\n",q,Dp(1,0));
	}
	return 0;
}
