#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int head[1005],point[40005],val[40005],nxt[40005],size;
int n,dist[1005],t[1005];
bool vis[1005];

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void spfa(){
	int i;
	memset(dist,-1,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(t,0,sizeof(t));
	dist[1]=0;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	bool f=1;
	while(!q.empty()&&f){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=nxt[i]){
			int j=point[i],v=dist[u]+val[i];
			if(dist[j]<v){
				dist[j]=v;
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
					t[j]++;
					if(t[j]>=n)f=0;
				}
			}
		}
	}
	if(f)printf("%d\n",dist[n]);
	else printf("-2\n");
}

int main(){
	int l,d;
	while(scanf("%d%d%d",&n,&l,&d)!=EOF){
		int i;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=l;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			if(a>b){
				int tmp=a;
				a=b;
				b=tmp;
			}
			add(a,b,v);
			add(b,a,-v);
		}
		for(i=1;i<=d;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			if(a>b){
				int tmp=a;
				a=b;
				b=tmp;
			}
			add(a,b,v);
			add(b,a,-v);
		}
		spfa();
	}
	return 0;
}
