#include<stdio.h>        //基本需要的头文件
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const ll INF=1LL<<60;
const int maxm=300005;
int head[maxm],nxt[maxm*2],point[maxm*2],size,pre[maxm];
ll dist[maxm],val[maxm*2];
int num[maxm*2];

void add(int a,int b,ll v,int i){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	num[size]=i;
	head[a]=size++;
	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	num[size]=i;
	head[b]=size++;
}

struct cmp{                    //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s){            //传入出发点和到达点
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i];
			if(dist[j]==-1||dist[j]>u.first+val[i]){
				dist[j]=u.first+val[i];
				q.push(make_pair(dist[j],j));
				pre[j]=i;
			}
			else if(dist[j]==u.first+val[i]){
				if(val[i]<val[pre[j]])pre[j]=i;
			}
		}
	}
}

int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	size=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=m;i++){
		int a,b;ll v;
		scanf("%d%d%I64d",&a,&b,&v);
		add(a,b,v,i);
	}
	int s;
	scanf("%d",&s);
	dij(s);
	ll ans=0;
	for(i=1;i<=n;i++){
		if(i==s)continue;
		ans+=val[pre[i]];
	}
	printf("%I64d\n",ans);
	for(i=1;i<=n;i++){
		if(i==s)continue;
		printf("%d ",num[pre[i]]);
	}
	printf("\n");
	return 0;
}
