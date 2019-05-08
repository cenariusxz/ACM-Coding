#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxm=150+10;
const int INF=0x3f3f3f3f;

int n,p;
int l[maxm],mach[maxm][15];

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct ISAP{
	int s,t,m,n;
	vector<edge>e;
	vector<int>g[maxm];
	int p[maxm],num[maxm],cur[maxm],d[maxm];
	bool vis[maxm];

	void init(int n){
		for(int i=0;i<=n+5;i++)g[i].clear();
		this->n=n;
		e.clear();
	}

	void add(int a,int b,int v){
		e.push_back(edge(a,b,v,0));
		e.push_back(edge(b,a,0,0));
		m=e.size();
		g[a].push_back(m-2);
		g[b].push_back(m-1);
	}

	void bfs(){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(t);
		vis[t]=1;
		d[t]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<g[u].size();i++){
				edge tmp=e[g[u][i]];
				if(!vis[tmp.to]&&!tmp.c){
					q.push(tmp.to);
					vis[tmp.to]=1;
					d[tmp.to]=d[u]+1;
				}
			}
		}
	}

	int Augment(){
		int x=t,a=INF;
		while(x!=s){
			edge tmp=e[p[x]];
			a=min(a,tmp.c-tmp.f);
			x=e[p[x]].from;
		}
		
		x=t;
		while(x!=s){
			e[p[x]].f+=a;
			e[p[x]^1].f-=a;
			x=e[p[x]].from;
		}
		return a;
	}

	int mf(int s,int t){
		memset(d,0,sizeof(d));
		this->s=s;this->t=t;
		int flow=0;
		bfs();
		memset(num,0,sizeof(num));
		for(int i=0;i<=n;i++)num[d[i]]++;
		int x=s;
		memset(cur,0,sizeof(cur));
		while(d[s]<n){
			if(x==t){
				flow+=Augment();
				x=s;
			}
			bool f=0;
			for(int i=cur[x];i<g[x].size();i++){
				edge tmp=e[g[x][i]];
				if(tmp.c>tmp.f&&d[x]==d[tmp.to]+1){
					f=1;
					p[tmp.to]=g[x][i];
					cur[x]=i;
					x=tmp.to;
					break;
				}
			}
			if(!f){
				int m=n-1;
				for(int i=0;i<g[x].size();i++){
					edge tmp=e[g[x][i]];
					if(tmp.c>tmp.f)m=min(m,d[tmp.to]);
				}
				if(--num[d[x]]==0)break;
				num[d[x]=m+1]++;
				cur[x]=0;
				if(x!=s)x=e[p[x]].from;
			}
		}
		return flow;
	}

};

int main(){
	while(scanf("%d%d",&p,&n)!=EOF){
		int i,j,k;
		ISAP I;
		I.init(2*n+1);
		memset(mach,0,sizeof(mach));
		for(i=1;i<=p;i++)mach[2*n+1][i]=1;
		l[2*n+1]=INF;
		for(i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(j=1;j<=p;j++)scanf("%d",&mach[i+n][j]);
			for(j=1;j<=p;j++)scanf("%d",&mach[i][j]);
			I.add(i+n,i,l[i]);
		}
		for(i=0;i<=n;i++){
			for(j=n+1;j<=2*n+1;j++){
				bool f=1;
				for(k=1;k<=p;k++){
					if((mach[j][k]==0||mach[j][k]==1)&&mach[i][k]!=mach[j][k]){f=0;break;}
				}
				if(f)I.add(i,j,INF);
			}
		}
		int ans=I.mf(0,2*n+1);
		printf("%d ",ans);
		ans=0;
		for(i=1;i<I.e.size();i+=2){
			if(I.e[i].f&&I.e[i].from>n&&I.e[i].from!=2*n+1&&I.e[i].to<=n&&I.e[i].to!=0){
				ans++;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<I.e.size();i+=2){
			if(I.e[i].f&&I.e[i].from>n&&I.e[i].from!=2*n+1&&I.e[i].to<=n&&I.e[i].to!=0){
				printf("%d %d %d\n",I.e[i].to,I.e[i].from-n,I.e[i].c-I.e[i].f);
			}
		}
	}
	return 0;
}
