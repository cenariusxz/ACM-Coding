#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
const int INF=0x7fffffff;
const int MAXN=30000;
using namespace std;
struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
int n,m,s,t;
vector <Edge>edges;
vector<int>G[MAXN];
bool vis[MAXN];
int d[MAXN];
int cur[MAXN];
void init()
{
	for(int i=0;i<=MAXN;i++)
		G[i].clear();
	edges.clear();
}
void AddEdge(int from,int to,int cap)
{
	edges.push_back(Edge(from,to,cap,0));
	edges.push_back(Edge(to,from,0,0));
	int w=edges.size();
	G[from].push_back(w-2);
	G[to].push_back(w-1);
}
bool BFS()
{
	memset(vis,0,sizeof(vis));
	queue<int>Q;
	Q.push(s);
	d[s]=0;
	vis[s]=1;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=0;i<G[x].size();i++)
		{
			Edge e=edges[G[x][i]];
			if(!vis[e.to]&&e.cap>e.flow)
			{
				vis[e.to]=1;
				d[e.to]=d[x]+1;
				Q.push(e.to);
			}
		}
	} 
	return vis[t];
}
int DFS(int x,int a)
{
	if(x==t||a==0)
		return a;
	int flow=0,f;
	for(int &i=cur[x];i<G[x].size();i++)
	{
		Edge e=edges[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
		{
			edges[G[x][i]].flow+=f;
			edges[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if(a==0)
				break;
		}
	}
	if(!flow)
		d[x]=-1;
	return flow;
}
int dinic(int s,int t)
{
	int flow=0;
	while(BFS())
	{
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
	}
	return flow;
}
int main()
{
	char str[105][105][10];
	char ans[105][105];
	bool used[105][105];
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		s=0;
		t=2*n*m+1;
		memset(used,0,sizeof(used));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%s",str[i][j]);
				if(str[i][j][0]=='.')
				{
					used[i][j]=1;
					AddEdge((i-1)*m+j,(i-1)*m+j+m*n,8);
				}
				else ans[i][j]='_';
			}
		}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(!used[i][j])
					{
						if(str[i][j][0]!='X')
						{
							int tmp=(str[i][j][0]-'0')*100+(str[i][j][1]-'0')*10+(str[i][j][2]-'0');
							int num=(i-1)*m+j;
							for(int k=i+1;k<=n&&used[k][j];k++)
							{
								tmp--;//下三角需要减掉的数 
								AddEdge(num,(k-1)*m+j,INF);
							}
							AddEdge(0,num,tmp);
						}				
						if(str[i][j][4]!='X')
						{
							int tmp=(str[i][j][4]-'0')*100+(str[i][j][5]-'0')*10+(str[i][j][6]-'0');
							int num=(i-1)*m+j+m*n;
							for(int k=j+1;k<=m&&used[i][k];k++)
							{
								tmp--;
								AddEdge((i-1)*m+k+m*n,num,INF);
							}
							AddEdge(num,t,tmp);
						}
					}
				}
			}
		dinic(s,t);
		for(i=0;i<edges.size();i++)
		{
			if(edges[i].from<=n*m&&edges[i].to>m*n)
			{
				int x=edges[i].from/m+1;
				int y=edges[i].from%m;
				if(y==0)
				{
					x--;
					y=m;
				}
				ans[x][y]=edges[i].flow+1+'0';
			} 
		}
		for(i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%c",ans[i][j]);
				if(j==m)
					printf("\n");
				else
					printf(" ");
			}
		}		
	}
	return 0;
}
