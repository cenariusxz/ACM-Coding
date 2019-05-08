#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int n,g[1005][1005],dist[1005],v[1005];
bool vis[1005];

void prim(){
	int i;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[1]=0;
	vis[1]=1;
	priority_queue<pii,vector<pii>,cmp>q;
	for(i=2;i<=n;i++){
		dist[i]=g[1][i];
		q.push(make_pair(dist[i],i));
	}
	int ans=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second])continue;
		ans+=u.first;
		vis[u.second]=1;
		for(i=1;i<=n;i++){
			if(!vis[i]&&dist[i]>g[u.second][i]){
				dist[i]=g[u.second][i];
				q.push(make_pair(dist[i],i));
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d",&n);
			int i,j;
			memset(g,0,sizeof(g));
			for(i=1;i<=n;i++)scanf("%d",&v[i]);
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					int l;
					scanf("%d",&l);
					if(i!=j){
						l=l+v[i]+v[j];
						if(l>g[i][j])g[i][j]=g[j][i]=l;
					}
				}
			}
			prim();
		}
	}
	return 0;
}
