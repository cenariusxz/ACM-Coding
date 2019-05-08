#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int maxn=555;

struct Point{
	int id,t;
	Point(){}
	Point(int a,int b):id(a),t(b){}
	bool operator < (Point a)const{
		return t<a.t;
	}
}p[maxn];

struct edge{
	int point,val;
	edge(int b,int c):point(b),val(c){}
};

int vis[maxn];
char s[maxn][maxn];
int g[maxn][maxn];
int v[maxn];
int n,k;
vector<edge> e[maxn];
bool f=0;

void dfs(int s,int t){
	if(f)return;
	v[t]=s;
	if(t==n-1){
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				if(g[s][i]&&g[i][1]){
					v[t+1]=i;
					for(int j=1;j<=n;++j){
						printf("%d",v[j]);
						if(j==n)printf("\n");
						else printf(" ");
					}
					f=1;
				}
				break;
			}
		}
		return;
	}	
	for(int i=0;i<e[s].size();++i){
		if(f)return;
		int j=e[s][i].point;
		if(!vis[j]){
			vis[j]=1;
			dfs(j,t+1);
			vis[j]=0;
		}
	}
}

bool cmp(edge a,edge b){
	return a.val<b.val;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i){
		queue<Point>q;
		vis[i]=1;
		q.push(Point(i,0));
		while(!q.empty()){
			Point u=q.front();
			q.pop();
			if(u.t>=k)break;
			for(int j=1;j<=n;++j){
				if(!vis[j]&&s[u.id][j]=='1'){
					vis[j]=1;
					q.push(Point(j,u.t+1));
				}
			}
		}
		int cnt=0;
		vis[i]=0;
		for(int j=1;j<=n;++j)if(vis[j]){g[i][j]=1;cnt++;}
		p[i].id=i;
		p[i].t=cnt;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(g[i][j]){
				e[i].push_back(edge(j,p[i].t+p[j].t));
			}
		}
		sort(e[i].begin(),e[i].end(),cmp);
	}
	vis[1]=1;
	dfs(1,1);
	return 0;
}
