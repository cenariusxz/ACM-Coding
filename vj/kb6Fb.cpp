#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

int g[2005][2005],n,dist[2005];
bool vis[2005];
char a[2005][10];

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

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
	printf("The highest possible quality is 1/%d.\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j,k;
		memset(g,0,sizeof(g));
		for(i=1;i<=n;i++)scanf("%s",a[i]);
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				int l=0;
				for(k=0;k<7;k++){
					if(a[i][k]!=a[j][k])l++;
				}
				g[i][j]=g[j][i]=l;
			}
		}
		prim();
	}
	return 0;
}
