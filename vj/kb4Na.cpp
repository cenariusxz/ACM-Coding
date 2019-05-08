#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int head[105],point[10005],next[10005],val[10005],size;
int n,s,t,dist[105];

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

void dij(){
	int i;
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(dist[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=head[u.second];~i;i=next[i]){
			int j=point[i],v=u.first+val[i];
			if(dist[j]==-1||dist[j]>v){
				dist[j]=v;
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",dist[t]);
}

int main(){
	while(scanf("%d%d%d",&n,&s,&t)!=EOF){
		int i,j;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=n;i++){
			int num;
			scanf("%d",&num);
			for(j=1;j<=num;j++){
				int b;
				scanf("%d",&b);
				add(i,b,j==1?0:1);
			}
		}
		dij();
	}
	return 0;
}
