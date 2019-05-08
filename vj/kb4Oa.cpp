#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int head[205],point[40005],val[40005],next[40005],size;
int dist[205],l[205],t,s[205],n;
bool vis[205],cir[205];

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

void spfa(){
	int i;
	memset(dist,-1,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(s,0,sizeof(s));
	memset(cir,0,sizeof(cir));
	dist[1]=0;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		if(s[u]>n){
			cir[u]=1;
			continue;
		}
		for(i=head[u];~i;i=next[i]){
			int j=point[i];
			if((dist[j]==-1||dist[j]>dist[u]+val[i])&&!cir[j]){
				dist[j]=dist[u]+val[i];
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
					s[j]++;
				}
			}
		}
	}
	int m;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&t);
		if(!cir[t]&&dist[t]>=3)printf("%d\n",dist[t]);
		else printf("?\n");
	}
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d",&n);
			int i;
			for(i=1;i<=n;i++){
				scanf("%d",&l[i]);
			}
			memset(head,-1,sizeof(head));
			size=0;
			int m;
			scanf("%d",&m);
			for(i=1;i<=m;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				int v=l[b]-l[a];
				v=v*v*v;
				add(a,b,v);
			}
			printf("Case %d:\n",q);
			spfa();
		}
	}
	return 0;
}
