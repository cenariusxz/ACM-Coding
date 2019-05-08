#include<stdio.h>        //基本需要的头文件
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],nxt[maxm<<1],val[maxm<<1],point[maxm<<1],size;
int dis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int v){	//若有向图则只需要前一半
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;

	point[sise]=a;
	val[size]=v;
	nxt[size]=head[b];
	head[b]=size++;
}

struct cmp{						//将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s,int t){			//传入出发点和到达点
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
	printf("%d\n",dis[t]);		//或去掉在主函数中输出或操作
}
