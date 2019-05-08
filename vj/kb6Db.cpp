#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

int n,g[105][105],dist[105];
bool vis[105];

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void prim(){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dist[1]=0;
	for(i=1;i<=n;i++){
		if(i!=1){
			dist[i]=g[1][i];
			q.push(make_pair(dist[i],i));
		}
	}
	int ans=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second])continue;
		ans+=u.first;
		vis[u.second]=1;
		for(i=1;i<=n;i++){
			if(!vis[i]){
				int j=g[u.second][i];
				if(j<dist[i]){
					dist[i]=j;
					q.push(make_pair(dist[i],i));
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		int i,j;
		memset(g,-1,sizeof(g));
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				int v;
				scanf("%d",&v);
				if(i!=j&&(g[i][j]==-1||g[i][j]>v))g[i][j]=g[j][i]=v;
			}
		}
		int q;
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a][b]=g[b][a]=0;
		}
		prim();
	}
	return 0;
}
