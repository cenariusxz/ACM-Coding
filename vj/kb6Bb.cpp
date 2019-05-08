#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

int head[55],point[2505],next[2505],val[2505],size,dist[55];
bool vis[55];

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

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void prim(int s){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dist,-1,sizeof(dist));
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	dist[s]=0;
	int ans=0;
	for(i=head[s];~i;i=next[i]){
		int j=point[i];
		dist[j]=val[i];
		q.push(make_pair(dist[j],j));
	}
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		ans+=u.first;
		for(i=head[u.second];~i;i=next[i]){
			int j=point[i];
			if(!vis[j]&&(dist[j]==-1||dist[j]>val[i])){
				dist[j]=val[i];
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		memset(head,-1,sizeof(head));
		size=0;
		int i;
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		prim(1);
	}
	return 0;
}
