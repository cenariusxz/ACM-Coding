#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<math.h>
#define max(a,b) a>b?a:b
using namespace std;
typedef pair<double,int> pii;
const double INF=100000.0;

int n;

struct point{
	int x,y;
}p[205];

double g[205][205],dist[205];

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s,int p){
	int i;
	for(i=1;i<=n;i++){
		dist[i]=INF;
	}
	dist[s]=0;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=1;i<=n;i++){
			double j=max(u.first,g[u.second][i]);
			if(i!=u.second&&dist[i]>j){
				dist[i]=j;
				q.push(make_pair(dist[i],i));
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
		dij(1,2);
	}
	return 0;
}
