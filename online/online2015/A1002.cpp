#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
typedef long long ll;
using namespace std;

const int maxn=100050;
const int maxm=200050;

int head[maxn],point[maxm],nxt[maxm],id[maxn],size,vis[maxn];
int v[maxn];
int n,m;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(id,0,sizeof(id));
	memset(vis,0,sizeof(vis));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
	id[a]++;
}

void topo(){
	queue<int>q;
	for(int i=1;i<=n;++i)if(id[i]==1){
		id[i]=-1;
		q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			id[j]--;
			if(id[j]==1){
				id[j]=-1;
				q.push(j);
			}
		}
	}
}

int nnum=0;
ll sum=0;

void dfs(int s){
	vis[s]=1;
	nnum++;
	sum+=v[s];
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]&&id[j]>0)dfs(j);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;++i)scanf("%d",&v[i]);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		topo();
		ll ans=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]&&id[i]>0){
				sum=0;
				nnum=0;
				dfs(i);
				if(nnum%2&&nnum>1)ans+=sum;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
