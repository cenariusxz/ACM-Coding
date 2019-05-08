#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxm=150+5;
const int INF=0x3f3f3f3f;

int n,p;
int mach[105][15],l[105];

struct edge{
	int from,to,c,f;
	edge(int a,int b,int m,int n):from(a),to(b),c(m),f(n){}
};

struct ek{
	int n,m;
	vector<edge>e;
	vector<int>g[maxm];
	int a[maxm];
	int p[maxm];

	void init(int n){
		for(int i=0;i<n+3;i++)g[i].clear();
		e.clear();
	}

	void add(int from,int to,int c){
		e.push_back(edge(from,to,c,0));
		e.push_back(edge(to,from,0,0));
		m=e.size();
		g[from].push_back(m-2);
		g[to].push_back(m-1);
	}

	int mf(int s,int t){
		int f=0;
		while(1){
			memset(a,0,sizeof(a));
			queue<int>q;
			q.push(s);
			a[s]=INF;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=0;i<g[u].size();i++){
					edge tmp=e[g[u][i]];
					if(!a[tmp.to]&&tmp.c>tmp.f){
						p[tmp.to]=g[u][i];
						a[tmp.to]=min(a[u],tmp.c-tmp.f);
						q.push(tmp.to);
					}
				}
				if(a[t])break;
			}
			if(!a[t])break;
			for(int i=t;i!=s;i=e[p[i]].from){
				e[p[i]].f+=a[t];
				e[p[i]^1].f-=a[t];

			}
			f+=a[t];
		}
		return f;
	}
};

int q;

int main(){
	int i,j,k;
	while(scanf("%d%d",&p,&n)!=EOF){
		ek E;
		E.init(n);
		memset(mach,0,sizeof(mach));
		for(i=1;i<=p;i++){
			mach[2*n+1][i]=1;
		}
		l[0]=l[2*n+1]=INF;
		for(i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(j=1;j<=p;j++){
				scanf("%d",&mach[i+n][j]);
			}
			for(j=1;j<=p;j++){
				scanf("%d",&mach[i][j]);
			}
			E.add(i+n,i,l[i]);
		}
		for(i=0;i<=n;i++){
			for(j=n+1;j<=2*n+1;j++){
				bool f=1;
				for(k=1;k<=p;k++){
					if((mach[j][k]==0||mach[j][k]==1)&&mach[i][k]!=mach[j][k]){f=0;break;}
				}
				if(f)E.add(i,j,INF);
			}
		}/*
		for(i=0;i<E.e.size();i++){
			printf("%d %d %d %d\n",E.e[i].from,E.e[i].to,E.e[i].c,E.e[i].f);
		}*/
		int ans=E.mf(0,2*n+1);
		printf("%d ",ans);
		ans=0;
		for(i=1;i<E.e.size();i+=2){
			if(E.e[i].f&&E.e[i].from>n&&E.e[i].to<=n&&E.e[i].from!=2*n+1&&E.e[i].to!=0){
				ans++;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<E.e.size();i+=2){
			if(E.e[i].f&&E.e[i].from>n&&E.e[i].to<=n&&E.e[i].from!=2*n+1&&E.e[i].to!=0){
				printf("%d %d %d\n",E.e[i].to,E.e[i].from-n,E.e[i].c-E.e[i].f);
			}
		}
	}
	return 0;
}
