#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator ()(pii a,pii b){
		return a.first>b.first;
	}
};

int head[105],point[10000],val[10000],next[10000],size;
int n,x,l[105],dist[105];

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

int dij(int s,int t){
	int i;
	memset(dist,0x3f,sizeof(dist));
	dist[0]=0;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(dist[0],0));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=head[u.second];~i;i=next[i]){
			int j=point[i];
			if(l[j]>=l[s]&&l[j]<=l[s]+x&&dist[j]>u.first+val[i]){
				dist[j]=u.first+val[i];
				q.push(make_pair(dist[j],j));
			}
		}
	}
	return dist[t];
}

int main(){
	while(scanf("%d%d",&x,&n)!=EOF){
		int i,j;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=n;i++){
			int num,b,v;
			scanf("%d%d%d",&v,&l[i],&num);
			add(0,i,v);
			for(j=1;j<=num;j++){
				scanf("%d%d",&b,&v);
				add(b,i,v);
			}
		}
		int ans=0x3f3f3f3f;
		for(i=1;i<=n;i++){
			int tmp=dij(i,1);
			if(ans>tmp)ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
