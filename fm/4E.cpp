#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=2e5+5;
const int maxm=6e5+5;
const int maxl=22;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,bcccnt,cutcnt;
int stx[maxn],low[maxn],bcc[maxn],cut[maxn];
int num[maxn];
vector<int>bccs[maxn];
stack<int>S;
int fa[maxl][maxn],dep[maxn],dis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
}

void add(int a,int b,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
	point[c][size[c]]=a;
	nxt[c][size[c]]=head[c][b];
	head[c][b]=size[c]++;
}

void dfs(int s,int pre){
	stx[s]=low[s]=++t;
	S.push(s);
	int son=0;
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(!stx[j]){
			son++;
			dfs(j,s);
			low[s]=min(low[s],low[j]);
			if(low[j]>=stx[s]){
				if(!cut[s]&&pre!=-1)cut[s]=++cutcnt;
				bcccnt++;
				bccs[bcccnt].clear();
				while(1){
					int u=S.top();S.pop();
					bcc[u]=bcccnt;
					bccs[bcccnt].push_back(u);
					if(u==j)break;
				}
				bcc[s]=bcccnt;
				bccs[bcccnt].push_back(s);
			}
		}
		else if(j!=pre)low[s]=min(stx[j],low[s]);
	}
	if(pre==-1){
		if(son==1)cut[s]=0;
		else cut[s]=++cutcnt;
	}
}

void setbcc(){
	memset(cut,0,sizeof(cut));
	memset(stx,0,sizeof(stx));
	memset(bcc,0,sizeof(bcc));
	t=bcccnt=cutcnt=0;
	for(int i=0;i<n;++i)if(!stx[i])dfs(i,-1);
	for(int i=1;i<=bcccnt;++i)num[i]=bccs[i].size();
	for(int i=1;i<=cutcnt;++i)num[bcccnt+i]=1;
	for(int i=1;i<=bcccnt;++i){
		for(int j=0;j<bccs[i].size();++j){
			if(cut[bccs[i][j]]){
				add(i,bcccnt+cut[bccs[i][j]],1);
			}
		}
	}
}

void Dfs(int s,int pre,int d){
	fa[0][s]=pre;
	dep[s]=d;
	if(pre==-1)dis[s]=num[s];
	else dis[s]=num[s]+dis[pre];
	for(int i=head[1][s];~i;i=nxt[1][i]){
		int j=point[1][i];
		if(j==pre)continue;
		Dfs(j,s,d+1);
	}
}

void Pre(){
	memset(dep,-1,sizeof(dep));
	for(int i=1;i<=bcccnt+cutcnt;++i){
		if(dep[i]==-1)Dfs(i,-1,0);
	}
	for(int k=0;k+1<maxl;++k){
		for(int v=1;v<=bcccnt+cutcnt;++v){
			if(fa[k][v]<0)fa[k+1][v]=-1;
			else fa[k+1][v]=fa[k][fa[k][v]];
		}
	}
}

int Lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(int k=maxl-1;k>=0;--k){
		if((dep[v]-dep[u])&(1<<k))
			v=fa[k][v];
	}
	if(u==v)return u;
	for(int k=maxl-1;k>=0;--k){
		if(fa[k][u]!=fa[k][v]){
			u=fa[k][u];
			v=fa[k][v];
		}
	}
	if(fa[0][u]!=fa[0][v])return -1;
	return fa[0][u];
}

int main(){
	int m;
	int c=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		setbcc();
		Pre();
		printf("Case #%d:\n",++c);
		int q;
		scanf("%d",&q);
		while(q--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(cut[a])a=bcccnt+cut[a];
			else a=bcc[a];
			if(cut[b])b=bcccnt+cut[b];
			else b=bcc[b];
			int lca=Lca(a,b);
			if(lca==-1)printf("%d\n",n);
			else{
				int ans=dis[a]+dis[b]-2*dis[lca]+num[lca]-(dep[a]+dep[b]-2*dep[lca]);
				printf("%d\n",n-ans);
			}
		}
		printf("\n");
	}
	return 0;
}
