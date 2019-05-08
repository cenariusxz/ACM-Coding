#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=505*505;

int n,t,scccnt;
int w,l;
int stx[maxn],low[maxn],scc[maxn];
int id[maxn],od[maxn];
int ma[505][505];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
stack<int>S;

int max(int a,int b){return a>b?a:b;}

inline int getid(int a,int b){
	return (a-1)*w+b;
}

inline void getpoint(int num,int &a,int &b){
	a=num/w;
	b=num%w;
	if(b)a++;
	else b=w;
}

void dfs(int s){
	stx[s]=low[s]=++t;
	S.push(s);
	int x,y;
	getpoint(s,x,y);
	for(int p=0;p<4;++p){
		int dx=x+xx[p],dy=y+yy[p];
		if(dx>=1&&dx<=l&&dy>=1&&dy<=w&&ma[dx][dy]<=ma[x][y]){
			int j=getid(dx,dy);
			if(!stx[j]){
				dfs(j);
				low[s]=min(low[s],low[j]);
			}
			else if(!scc[j]){
				low[s]=min(low[s],stx[j]);
			}
		}
	}
	if(low[s]==stx[s]){
		scccnt++;
		while(1){
			int u=S.top();S.pop();
			scc[u]=scccnt;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	t=scccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i);
	for(int i=1;i<=n;++i){
		int x,y;
		getpoint(i,x,y);
		for(int p=0;p<4;++p){
			int dx=x+xx[p],dy=y+yy[p];
			if(dx>=1&&dx<=l&&dy>=1&&dy<=w&&ma[dx][dy]<=ma[x][y]){
				int k=getid(dx,dy);
				if(scc[i]!=scc[k]){
					od[scc[i]]++;
					id[scc[k]]++;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&w,&l);
	n=w*l;
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
	for(int i=1;i<=l;++i){
		for(int j=1;j<=w;++j){
			scanf("%d",&ma[i][j]);
		}
	}
	setscc();
	if(scccnt==1)printf("0\n");
	else{
		int in=0,out=0;
		for(int i=1;i<=scccnt;++i){
			if(!id[i])in++;
			if(!od[i])out++;
		}
		printf("%d\n",max(in,out));
	}
}
