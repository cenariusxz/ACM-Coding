#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int head[1005],dist[1005],next[4005],point[4005],val[4005],size;
bool vis[1005];

void add(int a,int b,int v){
	int i;
	for(i=head[a];~i;i=next[i]){
		if(point[i]==b){
			if(val[i]>v)val[i]=v;
			return;
		}
	}
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

void spfa(int s,int p){
	memset(vis,0,sizeof(vis));
	memset(dist,-1,sizeof(dist));
	queue<int>q;
	vis[s]=1;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int i,t=q.front();
		vis[t]=0;
		q.pop();
		for(i=head[t];~i;i=next[i]){
			int j=point[i];
			if(dist[j]==-1||dist[j]>dist[t]+val[i]){
				dist[j]=dist[t]+val[i];
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	printf("%d\n",dist[p]);
}

int main(){
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF){
		int i,j;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=t;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		spfa(n,1);
	}
	return 0;
}
