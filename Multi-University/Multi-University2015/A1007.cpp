#include<stdio.h>                //差不多要加这么些头文件
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int maxm=2005;        //点的总数
const int INF=0x3f3f3f3f;

int head[2005],nxt[60005*2],point[60005*2],val[60005*2],size=0;
int dist[2005],d[2005],n,m;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void add(int a,int b,int v){
	val[size]=v;
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	val[size]=v;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

struct cmp{                    //将优先队列改为小根堆
    bool operator()(pii a,pii b){
        return a.first>b.first;
    }
};

void dij(){            //传入出发点和到达点
    int i;
    priority_queue<pii,vector<pii>,cmp>q;
    q.push(make_pair(0,1));
    memset(dist,-1,sizeof(dist));
    dist[1]=0;
	d[1]=0;
    while(!q.empty()){
        pii u=q.top();
        q.pop();
        if(u.first>dist[u.second])continue;
        for(i=head[u.second];~i;i=nxt[i]){
            int j=point[i];
            if(dist[j]==-1||dist[j]>u.first+val[i]){
                dist[j]=u.first+val[i];
                q.push(make_pair(dist[j],j));
				d[j]=d[u.second]+1;
            }
			else if(dist[j]==val[i]+u.first){
				if(d[j]>d[u.second]+1)d[j]=d[u.second]+1;
			}
        }
    }
}

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

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		size=0;
		dinic di;
		di.init(n);
		memset(head,-1,sizeof(head));
		for(i=1;i<=m;i++){
			int a,b,c;
			a=read();
			b=read();
			c=read();
			add(a,b,c);
		}
		dij();
		int ans2=m-d[n];
		for(i=1;i<=n;i++){
			for(j=head[i];~j;j=nxt[j]){
				int p=point[j];
				if(dist[i]+val[j]==dist[p])di.add(i,p,1);
			}
		}
		int ans1=di.mf(1,n);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
