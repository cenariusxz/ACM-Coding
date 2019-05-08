#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int head[505],next[6000],point[6000],val[6000],size;
int n,dis[505],t[505];
bool vis[505];

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

void spfa(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(t,0,sizeof(t));
	queue<int>q;
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	t[s]++;
	int i;
	bool f=1;
	while(!q.empty()&&f){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=next[i]){
			int j=point[i];
			if(dis[j]>dis[u]+val[i]){
				dis[j]=dis[u]+val[i];
				q.push(j);
				t[j]++;
				vis[j]=1;
				if(t[j]>n)f=0;
			}
		}
	}
	if(f)printf("NO\n");
	else printf("YES\n");
}

int main(){
	int f;
	while(scanf("%d",&f)!=EOF){
		for(int q=1;q<=f;q++){
			int w,m,i;
			scanf("%d%d%d",&n,&m,&w);
			memset(head,-1,sizeof(head));
			size=0;
			for(i=1;i<=m;i++){
				int a,b,v;
				scanf("%d%d%d",&a,&b,&v);
				add(a,b,v);
				add(b,a,v);
			}
			for(i=1;i<=w;i++){
				int a,b,v;
				scanf("%d%d%d",&a,&b,&v);
				add(a,b,-v);
			}
			spfa(1);
		}
	}
	return 0;
}
