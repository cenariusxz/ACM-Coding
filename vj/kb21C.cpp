#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int num[200],size;
int que[200][200];
int cnt[200];
double dp[200];
vector<int>v[100005];

void init(){
	for(int i=1;i<=100000;++i){
		for(int j=i;j<=100000;j+=i){
			v[j].push_back(i);
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		size=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=v[n].size()-1;i>=0;--i){
			num[++size]=v[n][i];
		}
		for(int i=1;i<=size;++i){
			for(int j=i+1;j<=size;++j){
				if(num[i]%num[j]==0)que[i][++cnt[i]]=j;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=size-1;i>=1;--i){
			for(int j=1;j<=cnt[i];++j){
				dp[i]+=(dp[que[i][j]]+(cnt[i]+1.0)/cnt[i])/cnt[i];
			}
		}
		printf("Case %d: %.10lf\n",q,dp[1]);
	}
	return 0;
}
