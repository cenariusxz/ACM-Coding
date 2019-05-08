#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1<<19;

int bit[maxn][19];		//1 pos
int cnt[maxn];			//1 cnt
int num[19];			//18 hang ~
int dp[19][maxn];
int ans[maxn];
int pre[maxn],nxt[maxn];
char m[19][19];
int res[19];

void init(){
	memset(cnt,0,sizeof(cnt));
	for(int j=0;j<(1<<18);++j){
		for(int i=0;i<18;++i){
			if(j&(1<<i))bit[j][cnt[j]++]=i;
		}
	}
}

int n;

int Solve(int p,int s){
	if(dp[p][s] != 0x3f3f3f3f) return dp[p][s];
	if(p >= n) return 0;
	int res = 0x3f3f3f3f;
	for(int i = 0; i < n; ++i){
		if(s & (1 << i)) continue;
		int tmp = Solve(p + 1,s | (1 << i)) + cnt[s & num[i]];
		if(tmp < res){
			res = tmp;
			nxt[s] = i;
		}
	}
	return dp[p][s] = res;
}

int main(){
	init();
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;++i)scanf("%s",m[i]);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i){
			for(int j=n-1;j>=0;--j){
				int tmp=m[i][j]-'0';
				num[i]=num[i]*2+tmp;
			}
		}
		memset(dp,0x3f,sizeof(dp));
		Solve(0,0);
		/*for(int j=0;j<(1<<n)-1;++j){
			for(int i=0;i<n;++i){
				if(j&(1<<i))continue;
				int nxtj=j+(1<<i);
				int add=cnt[j&num[i]];
				if(dp[j]+add<dp[nxtj]){
					dp[nxtj]=dp[j]+add;
					pre[nxtj]=j;
					ans[nxtj]=i;
				}
			}
		}*/
		int ts = 0;
		for(int i = 0; i < n; ++i){
			printf("%d",nxt[ts]);
			ts |= (1 << nxt[ts]);
			if(i < n - 1) printf(" ");
			else printf("\n");
		}
		printf("%d\n",dp[0][0]);
		//int pos=(1<<n)-1;
		//int c=n;
		/*
//		for(int i=0;i<(1<<n);++i)printf("%d : %d\n",i,dp[i]);
		while(pos){
			res[c--]=ans[pos];
			pos=pre[pos];
		}
		for(int i=1;i<=n;++i){
			printf("%d",res[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
		printf("%d\n",dp[(1<<n)-1]);
		*/
		
	}
	return 0;
}
