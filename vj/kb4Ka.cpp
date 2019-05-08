#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

int head[30005],point[150005],val[150005],next[150005],size;
int dist[30005];

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

void dij(int s,int t){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push(make_pair(dist[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=head[u.second];~i;i=next[i]){
			int j=point[i];
			if(dist[j]>dist[u.second]+val[i]){
				dist[j]=dist[u.second]+val[i];
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",dist[t]);
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		dij(1,n);
	}
	return 0;
}
