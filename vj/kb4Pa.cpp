#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int head[300005],point[1000005],val[1000005],nxt[1000005],size;
int n,dist[300005];

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void dij(){
	int i;
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(dist[1],1));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i],v=u.first+val[i];
			if(dist[j]==-1||dist[j]>v){
				dist[j]=v;
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",dist[n]);
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			printf("Case #%d: ",q);
			memset(head,-1,sizeof(head));
			size=0;
			int m,c;
			scanf("%d%d%d",&n,&m,&c);
			int i,j;
			for(i=1;i<=n;i++){
				int l;
				scanf("%d",&l);
				add(i,l+n,0);
				add(l+n+n,i,0);
			}
			for(i=1;i<n;i++){
				add(i+n,i+n+n+1,c);
				add(i+n+1,i+n+n,c);
			}
			for(i=1;i<=m;i++){
				int a,b,v;
				scanf("%d%d%d",&a,&b,&v);
				add(a,b,v);
				add(b,a,v);
			}
			dij();
		}
	}
	return 0;
}
