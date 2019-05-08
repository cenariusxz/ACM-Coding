#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

int dis[17][17];
int d[17];
int dp[65540][16];
int n,m;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(d,-1,sizeof(d));
	q.push(make_pair(0,s));
	d[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>d[u.second])continue;
		for(i=1;i<=n;++i){
			if(dis[i][u.second]!=-1){
				if(d[i]==-1||d[i]>u.first+dis[u.second][i]){
					d[i]=u.first+dis[u.second][i];
					q.push(make_pair(d[i],i));
				}
			}
		}
	}
	for(i=1;i<=n;++i)dis[s][i]=dis[i][s]=d[i];
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(dis,-1,sizeof(dis));
		for(int i=0;i<n;++i)dis[i][i]=0;
		for(int i=1;i<=m;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			if(a==b)continue;
			if(dis[a-1][b-1]==-1||dis[a-1][b-1]>v)dis[a-1][b-1]=dis[b-1][a-1]=v;
		}
		for(int i=0;i<n;++i)dij(i);
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=(1<<(n-1))-1;++i){
			for(int j=1;j<n;++j){
				if((1<<(j-1))&i){
					if(dp[i][j]==-1)dp[i][j]=dp[i-(1<<(j-1))]
				}
			}
		}
	}
	return 0;
}
