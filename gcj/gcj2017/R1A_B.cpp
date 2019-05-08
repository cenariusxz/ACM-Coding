#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;
const int maxm=150+5;        //点的总数

struct edge{             //弧的结构体，变量：弧的出发点、结束点、容量、流量
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct dinic{
	int m,s,t;                    //边数、源点标号、汇点标号
	vector<edge>e;        //边
	vector<int>g[maxm];    //g[i][j]表示第i个点出发的第j条边在e中的编号
	bool vis[maxm];
	int d[maxm],cur[maxm];    //d为源点到点的距离，cur为当前遍历到的边
	void init(int n){                //初始化，n为点数量（标号0～n-1）
		for(int i=0;i<n+5;i++)g[i].clear();
		e.clear();
	}
	void add(int a,int b,int v){        //加入弧和反向弧
		e.push_back(edge(a,b,v,0));    //正向弧容量v，反向弧容量0
		e.push_back(edge(b,a,0,0));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}
	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.c>tmp.f){
					vis[tmp.to]=1;
					d[tmp.to]=d[u]+1;
					q.push(tmp.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		for(int& i=cur[x];i<g[x].size();i++){
			edge &tmp=e[g[x][i]];
			if(d[x]+1==d[tmp.to]&&(f=dfs(tmp.to,min(a,tmp.c-tmp.f)))>0){
				tmp.f+=f;
				e[g[x][i]^1].f-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(!flow)d[x]=-1;
		return flow;
	}
	int mf(int s,int t){                //在主函数中使用的函数，求s到t的最大流
		this->s=s;
		this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
};

int Q[55][55];
int R[55];
int n,p;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;++i)scanf("%d",&R[i]);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=p;++j)scanf("%d",&Q[i][j]);
		}
		printf("Case #%d: ",q);
		if(n==1){
			int ans=0;
			for(int i=1;i<=p;++i){
				int l1,r1;
				l1=Q[1][i]/1.1/R[1];
				while(1.1*R[1]*l1<Q[1][i])l1++;
				r1=Q[1][i]/0.9/R[1];
//				printf("%d %d\n",l1,r1);
				if(l1<=r1)ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		if(n==2){
			dinic D;
			D.init(n*p+1);
			for(int j=1;j<=p;++j){
				D.add(0,j,1);
				int l1,r1;
				l1=Q[1][j]/1.1/R[1];
				while(1.1*R[1]*l1<Q[1][j])l1++;
				r1=Q[1][j]/0.9/R[1];
				if(l1>r1)continue;
				for(int k=1;k<=p;++k){
					int l2,r2;
					l2=Q[2][k]/1.1/R[2];
					while(1.1*R[2]*l2<Q[2][k])l2++;
					r2=Q[2][k]/0.9/R[2];
					if(l2>r2)continue;
					if(!(l1>r2||r1<l2)){
						D.add(j,p+k,1);
		//				printf("%d %d %d %d\n",l1,r1,l2,r2);
					}
				}
			}
			for(int i=1;i<=p;++i)D.add(p+i,p+p+1,1);
			printf("%d\n",D.mf(0,p+p+1));
		}

	}
	return 0;
}
