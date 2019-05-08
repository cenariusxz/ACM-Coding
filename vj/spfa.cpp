#include<stdio.h>				//spfa基本上要这些头文件
#include<string.h>
#include<queue>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int head[maxn],point[maxm<<1],nxt[maxm<<1],val[maxm<<1],size;
int dis[maxn],vis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int v){	//有向图只需要前一半
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;

	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	head[b]=size++;
}

void spfa(int s,int t){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	vis[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[t];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]>dis[u]+val[i]){
				dis[j]=dis[u]+val[i];
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	printf("%d\n",dis[t]);
}
