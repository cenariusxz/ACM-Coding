#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int dp[55][15][90];
int pre[55][15][90];
int a[55],w[4];
int ans[100005];
int n,q;
int ask[100005];

void check(int i){
	w[1]=w[2]=w[3]=-1;
	int cnt=0;
	for(int i=0;i<n;++i){
		if(ask[i]&(1<<i))w[++cnt]=i;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	pre[0][0][0]=-1;
	if(a[1]<=87){
		dp[0][1][a[1]]=1;
		pre[0][1][a[1]]=-1;
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<=max(10,i);++j){
			for(int k=0;k<=87;++k){
				if(dp[i-1][j][k]==1){
					dp[i][j][k]=1;
					pre[i][j][k]=pre[i-1][j][k];
					if(k+a[i]<=87){
						dp[i][j+1][k+a[i]]=1;
						pre[i][j+1][k+a[i]]=i;
					}
				}
			}
		}
	}
	for(int i=1;i<n;++i){

	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		scanf("%d",&q);
		memset(ans,0,sizeof(ans));
		memset(ask,0,sizeof(ask));
		for(int i=1;i<=q;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ask[i]|=(1<<(a-1));
			ask[i]|=(1<<(b-1));
			ask[i]|=(1<<(c-1));
		}
		for(int i=1;i<=q;++i){
			if(!ans[i])check(i);
		}
		for(int i=1;i<=q;++i){
			if(ans[i])printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
