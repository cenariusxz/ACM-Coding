#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxm=2e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int vis[maxn],id[maxn];
int dp[maxn][3][2];
int n;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(id,0,sizeof(id));
	memset(dp,0x3f,sizeof(dp));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s,int fa){
	if(id[s]==1){
		dp[s][0][1]=0;
		dp[s][1][0]=0;
		return;
	}
	if(id[s]==2&&fa!=-1){
		for(int i=head[s];~i;i=nxt[i]){
			int j=point[i];
			if(j==fa)continue;
			dp[s][0][1]=dp[j][0][1]+1;
			dp[s][1][0]=dp[j][1][0]+1;
		}
	}
	int cnt=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==fa)continue;
		dfs(j,s);
		cnt++;
		if(cnt==1){
			dp[s][0][1]=min(dp[s][0][1],dp[j][0][1]+1);
			dp[s][1][0]=min(dp[s][1][0],dp[j][1][0]+1);
			dp[s][1][1]=min(dp[s][1][1],dp[j][1][1]+1);
			dp[s][2][0]=min(dp[s][2][0],dp[j][2][0]+2);
			dp[s][2][1]=min(dp[s][2][1],dp[j][2][1]+2);
		//	if(s==1)printf("%d\n",dp[s][1][0]);
		}
		else{
		//	if(s==2)printf("%d\n",dp[s][1][0]);
			int p[3][2]={INF,INF,INF,INF,INF,INF};
			for(int a=0;a<=2;++a){
				for(int b=0;b<=1;++b){
					for(int c=0;c<=2;++c){
						if(a==0&&c==0)continue;
						for(int d=0;d<=1;++d){
							if(b==1&&d==1)continue;
							int k1=a+c;
							if(k1>2)k1-=2;
							int k2=b|d;
						//	if(a==1&&b==0&&c==1&&d==0){
						//		printf("%d %d %d %d\n",k1,k2,dp[s][a][b],dp[j][c][d]);
						//	}
					//		if(s==2&&k1==1&&k2==0)printf("%d %d %d %d %d %d\n",dp[s][a][b],dp[j][c][d],a,b,c,d);
							p[k1][k2]=min(p[k1][k2],dp[s][a][b]+dp[j][c][d]+max(c,1));
						}
					}
				}
			}
			for(int a=0;a<=2;++a){
				for(int b=0;b<=1;++b){
					dp[s][a][b]=p[a][b];
				}
			}
		//	if(s==2)printf("%d\n",dp[s][1][0]);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
			id[a]++;
			id[b]++;
		}
		if(n==1||n==0){printf("0\n");continue;}
		if(n==2){printf("1\n");continue;}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(id[i]==1)cnt++;
		}
		for(int i=1;i<=n;++i){
			if(id[i]>1){
				dfs(i,-1);
//				printf("%d\n",i);
				if(cnt%2)printf("%d\n",dp[i][2][1]);
				else printf("%d\n",dp[i][2][0]);
				break;
			}
		}
//		printf("%d %d\n",dp[2][2][0],dp[3][2][0]);
//		printf("aaa:%d %d\n",dp[2][1][0],dp[3][1][0]);
	}
	return 0;
}
