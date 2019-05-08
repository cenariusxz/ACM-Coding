#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=1000;
const int INF=0x7fffffff;

struct edge{
	int from,to,f;
	edge(int a,int b,int c):from(a),to(b),f(c){}
};

struct dinic{
	int s,t,m;
	vector<edge>e;
	vector<int>g[maxm];
	bool vis[maxm];
	int cur[maxm],d[maxm];

	void init(int n){
		for(int i=1;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c){
		e.push_back(edge(a,b,c));
		e.push_back(edge(b,a,0));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}

	bool bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		vis[s]=1;
		d[s]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&tmp.f>0){
					d[tmp.to]=d[u]+1;
					vis[tmp.to]=1;
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
			edge& tmp=e[g[x][i]];
			if(d[tmp.to]==d[x]+1&&tmp.f>0){
				f=dfs(tmp.to,min(a,tmp.f));
				tmp.f-=f;
				e[g[x][i]^1].f+=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		if(flow==0)d[x]=-1;
		return flow;
	}

	int mf(int s,int t){
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

char a[25][25],b[25][25];
struct point{
	int x,y,n;
}p[500];

int aabs(int a){
	return a>=0?a:-a;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int i,j;
		int n,m,k;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		for(i=1;i<=n;i++){
			scanf("%s",b[i]+1);
		}
		m=strlen(a[1]+1);
		dinic d;
		d.init(n*m*2+10);
		int cnt=0,l,c=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j]!='0'){
					int tmp=(i-1)*m+j;
					d.add(tmp,tmp+m*n,a[i][j]-'0');
					for(l=1;l<=cnt;l++){
						if(aabs(i-p[l].x)+aabs(j-p[l].y)<=k){
							d.add(tmp+m*n,p[l].n,INF);
							d.add(p[l].n+n*m,tmp,INF);
						}
					}
					cnt++;
					p[cnt].x=i;
					p[cnt].y=j;
					p[cnt].n=tmp;
					if(b[i][j]=='L'){
						c++;
						d.add(0,tmp,1);
					}
					if(i<=k||j<=k||n-i+1<=k||m-j+1<=k)d.add(tmp+n*m,n*m*2+1,INF);
				}
			}
		}
		int ans=c-d.mf(0,2*n*m+1);
		printf("Case #%d: ",q);
		if(ans)printf("%d",ans);
		else printf("no");
		if(ans<=1)printf(" lizard was left behind.\n");
		else printf(" lizards were left behind.\n");
	}
	return 0;
}
