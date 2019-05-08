#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#define max(a,b) a>b?a:b
const double INF=10000.0;
using namespace std;

struct point{
	int x,y;
}p[205];

double g[205][205],dist[205];
bool vis[205];
int n;

void spfa(int s,int p){
	int i;
	for(i=1;i<=n;i++){
		dist[i]=INF;
	}
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(i=1;i<=n;i++){
			double j=max(dist[u],g[u][i]);
			if(i!=u&&dist[i]>j){
				dist[i]=j;
				if(!vis[i]){
					q.push(i);
					vis[i]=1;
				}
			}
		}
	}
	printf("%.3lf\n\n",dist[p]);
}

int main(){
	int c=0;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			for(j=1;j<=i;j++){
				g[i][j]=g[j][i]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)*1.0+(p[i].y-p[j].y)*(p[i].y-p[j].y)*1.0);
			}
		}
		printf("Scenario #%d\nFrog Distance = ",++c);
		spfa(1,2);
	}
	return 0;
}
