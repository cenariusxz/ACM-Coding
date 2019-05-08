#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

int head[1005],dist[1005],point[4005],val[4005],next[4005],size;

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

void dij(int s){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	while(!q.empty()){
		pii p=q.top();
		q.pop();
		if(p.first>dist[p.second])continue;
		for(i=head[p.second];~i;i=next[i]){
			int j=point[i];
			if(dist[j]==-1||dist[j]>p.first+val[i]){
				dist[j]=p.first+val[i];
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",dist[1]);
}

int main(){
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF){
		int i,j;
		size=0;
		memset(head,-1,sizeof(head));
		for(i=1;i<=t;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		dij(n);
	}
	return 0;
}
