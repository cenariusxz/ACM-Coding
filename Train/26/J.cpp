#include<stdio.h>        //基本需要的头文件
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=3e5+5;
const int maxm=4e5+5;

int head[maxn],nxt[maxm<<1],val[maxm<<1],point[maxm<<1],size;
int dis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int v){    //若有向图则只需要前一半
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s,int t){            //传入出发点和到达点
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis,-1,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]==-1||dis[j]>u.first+val[i]){
				dis[j]=u.first+val[i];
				q.push(make_pair(dis[j],j));
			}
		}
	}
	printf("%d\n",dis[t]);        //或去掉在主函数中输出或操作
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		init();
		int n,m,c;
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;++i){
			int cnt;
			scanf("%d",&cnt);
			add(i,n+cnt,c);
			add(n+n+cnt,i,0);
		}
		for(int i=2;i<=n;++i){
			add(n+i,n+n+i-1,0);
			add(n+i-1,n+n+i,0);
		}
		while(m--){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		printf("Case #%d: ",q);
		dij(1,n);	
	}
	return 0;
}
