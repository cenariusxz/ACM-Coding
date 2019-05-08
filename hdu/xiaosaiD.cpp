#include<stdio.h>    //大概要这些头文件
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

int ma[105][105];
bool vis[105];
int n;
int dist[105];
	
struct cmp{    //重载小根堆
	bool operator()(pii a,pii b){
		return a.first<b.first;
	}
};

void prim(){    //prim函数，传入图中一点
	int i,ans=0;
	memset(dist,-1,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,cmp>q;
	for(i=2;i<=n;++i){
		dist[i]=ma[1][i];
		q.push(make_pair(dist[i],i));
	}
	dist[1]=0;
	vis[1]=1;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		ans+=u.first;
		for(i=1;i<=n;++i){
			if(i==u.second)continue;
			int j=i;
			if(!vis[j]&&(dist[j]<ma[u.second][j])){
				dist[j]=ma[u.second][j];
				q.push(make_pair(dist[j],j));
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)scanf("%d",&ma[i][j]);
		}
		prim();
	}
	return 0;
}
