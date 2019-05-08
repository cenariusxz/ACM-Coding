#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1ll<<62;
const int mod=1e9+7;

ll dp[2][20][65550];
ll a[20];
int p[20];
int num[20];
vector<int> bit[2][65550];
vector<int> b[20];

void init(){
	for(int i=0;i<=(1<<16)-1;++i){
		for(int j=0;j<16;++j){
			if(i&(1<<j))bit[1][i].push_back(j);
			else bit[0][i].push_back(j);
		}
		b[bit[1][i].size()].push_back(i);
	}
}

void update(int now,int i,int j,int nxti){
	int nxt=now^1;
	int nxtj=j+(1<<nxti);
	if(dp[now][i][j]+a[i]*a[nxti]>dp[nxt][nxti][nxtj])dp[nxt][nxti][nxtj]=dp[now][i][j]+a[i]*a[nxti];
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		memset(num,-1,sizeof(num));
		for(int i=0;i<n;++i){
			scanf("%I64d%d",&a[i],&p[i]);
			if(p[i]!=-1)num[p[i]]=i;
		}
		memset(dp,-1,sizeof(dp));
		if(num[0]==-1){
			for(int i=0;i<n;++i){
				if(p[i]!=-1)continue;
				dp[0][i][1<<i]=0;
			//	printf("dp[%d][%d][%d]=%d\n",0,i,1<<i,0);
			}
		}
		else{
			dp[0][num[0]][1<<num[0]]=0;
		}
		for(int count=0;count<n;++count){
			int now=count&1;
			int nxt=now^1;
			for(int j=0;j<n;++j){
				for(int k=0;k<(1<<n);++k)dp[nxt][j][k]=-INF;
			}
			if(num[count]!=-1){
				int i=num[count];
				for(int x=0;x<b[count+1].size();++x){
					int j=b[count+1][x];
					if(j>=(1<<n))break;
					if(!(j&(1<<i)))continue;
					if(num[count+1]!=-1){
						int nxti=num[count+1];
						update(now,i,j,nxti);
					}
					else{
						for(int y=0;y<bit[0][j].size();++j){
							int nxti=bit[0][j][y];
							if(nxti>=n)break;
							if(p[nxti]!=-1)continue;
							update(now,i,j,nxti);
						}
					}
				}
			}
			else{
				for(int x=0;x<b[count+1].size();++x){
					int j=b[count+1][x];
					if(j>=(1<<n))break;
					for(int y=0;y<bit[1][j].size();++y){
						int i=bit[1][j][y];
						if(p[i]!=-1)continue;
						if(num[count+1]!=-1){
							int nxti=num[count+1];
							update(now,i,j,nxti);
						}
						else{
							for(int z=0;z<bit[0][j].size();++z){
								int nxti=bit[0][j][z];
								if(nxti>=n)break;
								if(p[nxti]!=-1)continue;
								update(now,i,j,nxti);
							}
						}
					}
				}
			}
		}
		int now=(n-1)&1;
		ll ans=-INF;
		for(int i=0;i<n;++i)if(dp[now][i][(1<<n)-1]>ans)ans=dp[now][i][(1<<n)-1];
		printf("Case #%d:\n%I64d\n",q,ans);
	}
	return 0;
}
