#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=10000+100;
const int INF=0x3f3f3f3f;

struct edge{
	int from,to,c,f,cost;
	edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
	return a>=0?a:-a;
}

struct MUMF{
	int m,s,t;
	vector<edge>e;
	vector<int>g[maxm];
	int dis[maxm],a[maxm],p[maxm];
	bool vis[maxm];

	void init(int n){
		for(int i=0;i<=n;i++)g[i].clear();
		e.clear();
	}

	void add(int a,int b,int c,int v){
		e.push_back(edge(a,b,c,0,v));
		e.push_back(edge(b,a,0,0,-v));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}

	bool spfa(int& flow,int& cost){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		vis[s]=1;
		dis[s]=0;
		p[s]=0;
		a[s]=INF;
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
					dis[tmp.to]=dis[u]+tmp.cost;
					p[tmp.to]=g[u][i];
					a[tmp.to]=min(a[u],tmp.c-tmp.f);
					if(!vis[tmp.to]){
						q.push(tmp.to);
						vis[tmp.to]=1;
					}
				}
			}
		}
		if(dis[t]==INF)return 0;
		flow+=a[t];
		cost+=dis[t]*a[t];
		int u=t;
		while(u!=s){
			e[p[u]].f+=a[t];
			e[p[u]^1].f-=a[t];
			u=e[p[u]].from;
		}
		return 1;
	}

	int MF(int s,int t){
		this->s=s;this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}

};

char a[105][105];
int xm[105],ym[105],xh[105],yh[105];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0||m!=0){
		MUMF M;
		int i,j;
		int cm=0,ch=0;
		for(i=1;i<=n;i++)scanf("%s",a[i]+1);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j]=='m'){
					cm++;
					xm[cm]=i;
					ym[cm]=j;
				}
				else if(a[i][j]=='H'){
					ch++;
					xh[ch]=i;
					yh[ch]=j;
				}
			}
		}
	//	printf("%d %d\n",cm,ch);
		M.init(cm+ch+5);
		for(i=1;i<=cm;i++)M.add(0,i,1,0);
		for(i=1;i<=ch;i++)M.add(cm+i,cm+ch+1,1,0);
		for(i=1;i<=cm;i++){
			for(j=1;j<=ch;j++){
				M.add(i,cm+j,1,aabs(xm[i]-xh[j])+aabs(ym[i]-yh[j]));
			}
		}
		printf("%d\n",M.MF(0,cm+ch+1));
/*		for(i=0;i<M.e.size();i+=2){
			printf("%d %d %d %d %d\n",M.e[i].from,M.e[i].to,M.e[i].c,M.e[i].f,M.e[i].cost);
		}
*/
	}
	return 0;
}
