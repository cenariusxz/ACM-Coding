#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=1005;
const int maxm=30005;
const int INF=0x3f3f3f3f;

int head[maxn],nxt[maxm],point[maxm],val[maxm],size;
int vis[maxn],dis[maxn],n,num[maxn];

void add(int a,int b,int v){
	val[size]=v;
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int spfa(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(num,0,sizeof(num));
	queue<int>q;
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]>dis[u]+val[i]){
				dis[j]=dis[u]+val[i];
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
					if(++num[j]>n)return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	int ml,md;
	scanf("%d%d%d",&n,&ml,&md);
	size=0;
	memset(head,-1,sizeof(head));
	while(ml--){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add(a,b,v);
	}
	while(md--){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add(b,a,-v);
	}
	for(int i=1;i<n;++i)add(i+1,i,0);
	if(spfa())printf("-1\n");
	else if(dis[n]==INF)printf("-2\n");
	else printf("%d\n",dis[n]);
	return 0;
}
