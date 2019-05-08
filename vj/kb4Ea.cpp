#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int head[1005],point[2005],next[2005],size,t[2005],n,m;
double r[2005],c[2005],dist[1005];
bool vis[1005];

void add(int a,int b,double r1,double c1){
	point[size]=b;
	r[size]=r1;
	c[size]=c1;
	next[size]=head[a];
	head[a]=size++;
}

void spfa(int s,double v){
	int i;
	memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(t,0,sizeof(t));
	dist[s]=v;
	queue<int>q;
	q.push(s);
	vis[s]=1;
	bool f=0;
	while(!q.empty()){
		if(f)break;
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=next[i]){
			int j=point[i];
			if(dist[j]<(dist[u]-c[i])*r[i]){
				dist[j]=(dist[u]-c[i])*r[i];
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
					t[j]++;
					if(t[j]>n)f=1;
				}
			}
		}
	}
	if(f)printf("YES\n");
	else printf("NO\n");
}

int main(){
	int s,i;
	double v;
	while(scanf("%d%d%d%lf",&n,&m,&s,&v)!=EOF){
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=m;i++){
			int a,b;
			double r1,c1;
			scanf("%d%d%lf%lf",&a,&b,&r1,&c1);
			add(a,b,r1,c1);
			scanf("%lf%lf",&r1,&c1);
			add(b,a,r1,c1);
		}
		spfa(s,v);
	}
	return 0;
}
