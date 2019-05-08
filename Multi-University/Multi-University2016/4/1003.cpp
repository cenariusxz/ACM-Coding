#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=25;
const int maxm=1000;

struct seg{
	int a,b;
}s[1000];
int w[100][100],val[100];
int dp[1050000];
int sum1[1050000],sum2[1050000];
int vis[1050000];
int n,m;

void init(){
	memset(w,0,sizeof(w));
	memset(val,0,sizeof(val));
	memset(vis,0,sizeof(vis));
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	memset(dp,0,sizeof(dp));
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		init();
		scanf("%d%d",&n,&m);
		if(m == 0) continue;
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%d%d",&s[i].a,&s[i].b);
			w[s[i].a][s[i].b] = w[s[i].b][s[i].a] = 1;
		}
		for(int i=0;i<n;++i)
			for(int j=n-1;j>=0;--j)
				val[i]=val[i]*2+w[i][j];
		dp[0]=0;
		vis[1]=1;
		for(int i=1;i<(1<<n);++i) if(vis[i]){
			for(int j=0;j<n;++j) if(!(i & (1 << j))){
				int nxt=i+(1<<j);
				if(nxt == (1 << n) - 1) continue;
				if(!vis[nxt] && (i&val[j])){
					dp[nxt]=dp[i]+__builtin_popcount(i&(val[j]));
					vis[nxt]=1;
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < (1 << n) - 1; ++i) if((i & 1) && vis[i]){
			int nxt = i ^ ((1 << n) - 1);
			sum1[i] = sum2[nxt] = 1;
			cnt++;
		}
		for(int i = 0; i < n; ++i){
			for(int j = (1 << n) - 1; j >= 0; --j) if(j & (1 << i)){
				sum1[j ^ (1 << i)] += sum1[j];
				sum2[j ^ (1 << i)] += sum2[j];
			}
		}
		if(q == 37){
			printf("%d %d\n",n,m);
			for(int i = 1; i <= m; ++i){
				printf("%d %d\n",s[i].a,s[i].b);
			}
		
		printf("Case #%d:",q);
		for(int i=1;i<=m;++i){
			int sta=(1<<s[i].a)+(1<<s[i].b);
			printf(" %d",cnt-sum1[sta]-sum2[sta]);
		}
		printf("\n");
		}
	}
	return 0;
}

