#include<stdio.h>        //基本需要的头文件
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=1e5+5;
const int maxm=2e5+5;

int head[maxn],nxt[maxm],val[maxm],point[maxm],size,co[maxm];
ll dis[maxn];
//int from[maxm],to[maxm],cost[maxm],cntm;
//int pre[maxn],id[maxn],vis[maxn],in[maxn];
int n,m;
int res[maxn];

void init(){
	memset(head,-1,sizeof(head));
	memset(res,0x3f,sizeof(res));
	size=0;
}

void add(int a,int b,int v,int c){    //若有向图则只需要前一半
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	co[size]=c;
	head[a]=size++;

	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	co[size]=c;
	head[b]=size++;
}

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(){            //传入出发点和到达点
	int s=1;
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]>u.first+val[i]){
				dis[j]=u.first+val[i];
				q.push(make_pair(dis[j],j));
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a++;
			b++;
			add(a,b,c,d);
		}
		dij();
		for(int s=1;s<=n;++s){
			for(int i=head[s];~i;i=nxt[i]){
				int j=point[i];
				if(dis[j]==dis[s]+val[i]){
					res[j]=min(res[j],co[i]);
				}
			}
		}
		ll ans1=0,ans2=0;
		for(int i=2;i<=n;++i)ans1+=dis[i];
		for(int i=2;i<=n;++i)ans2+=res[i];
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
