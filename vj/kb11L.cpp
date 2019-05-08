#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=20500;
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
			scanf("%d",&a);
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

	void mf(int s,int t){
		this->s=s;
		this->t=t;
		int flow=0;
		while(bfs()){
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
	}
};

char s[105][105][10];
bool vis[105][105];
char ans[105][105];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j,k;
		memset(vis,0,sizeof(vis));
		dinic d;
		d.init(n*m*2+10);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%s",s[i][j]+1);
				if(s[i][j][1]=='.'){
					vis[i][j]=1;
					d.add((i-1)*m+j,(i-1)*m+j+n*m,8);
				}
				else ans[i][j]='_';
			}
		}
		int t=n*m*2+1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(!vis[i][j]){
					if(s[i][j][1]!='X'){
						int tmp=(s[i][j][1]-'0')*100+(s[i][j][2]-'0')*10+(s[i][j][3]-'0'),num=(i-1)*m+j;
						for(k=i+1;k<=n&&vis[k][j];k++){
							tmp--;
							d.add(num,(k-1)*m+j,INF);
						}
						d.add(0,num,tmp);
					}
					if(s[i][j][5]!='X'){
						int tmp=(s[i][j][5]-'0')*100+(s[i][j][6]-'0')*10+(s[i][j][7]-'0'),num=(i-1)*m+j+n*m;
						for(k=j+1;k<=m&&vis[i][k];k++){
							tmp--;
							d.add((i-1)*m+k+n*m,num,INF);
						}
						d.add(num,t,tmp);
					}
				}
			}
		}
		for(i=0;i<d.e.size();i+=2){
			printf("%d %d %d\n",d.e[i].from,d.e[i].to,d.e[i].f);
		}
		d.mf(0,t);
		for(i=0;i<d.e.size();i++){
			if(d.e[i].from<=n*m&&d.e[i].to>n*m){
			int x=d.e[i].from/m+1,y=d.e[i].from%m;
			if(y==0){y=m;x--;}
				ans[x][y]=8-d.e[i].f+1+'0';
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				printf("%c",ans[i][j]);
				if(j==m)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
