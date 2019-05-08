#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<double,int> pii;
const int INF=0x3f3f3f3f;

int n;
double dist[105],g[105][105];
bool vis[105];
struct cell{
	double x,y,z,r;
}c[105];

struct cmp{
	bool operator()(pii a,pii b){
		return a.first-b.first>1e-10;
	}
};

void prim(int s){
	int i;
	for(i=1;i<=n;i++){
		dist[i]=INF;
	}
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	priority_queue<pii,vector<pii>,cmp>q;
	for(i=1;i<=n;i++){
		if(i!=s)dist[i]=g[s][i];
		q.push(make_pair(dist[i],i));
	}
	vis[s]=1;
	double ans=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		ans+=u.first;
		for(i=1;i<=n;i++){
			int j=u.second;
			if(!vis[i]&&i!=j&&dist[i]-g[j][i]>1e-10){
				dist[i]=g[j][i];
				q.push(make_pair(dist[i],i));
			}
		}
	}
	printf("%.3lf\n",ans);

}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&c[i].x,&c[i].y,&c[i].z,&c[i].r);
			for(j=1;j<i;j++){
			double l=sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y)+(c[i].z-c[j].z)*(c[i].z-c[j].z))-c[i].r-c[j].r;
			if(l-0<=1e-10)l=0;
			g[i][j]=g[j][i]=l;
			}
		}
		prim(1);
	}
	return 0;
}
