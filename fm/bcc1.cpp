#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;

struct edge{
	int u,v;
};

int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int>bcc[maxn];
int head[maxn],point[maxm],nxt[maxm],size;

stack<edge>S;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int u,int fa){
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for(int i=head[u];~i;i=nxt[i]){
		int v=point[i];
		edge e=(edge){u,v};
		if(!pre[v]){
			S.push(e);
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u]){
				iscut[u]=1;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while(1){
					edge x=S.top();
					S.pop();
					if(bccno[x.u]!=bcc_cnt){bcc[bcc_cnt].push_back(x.u);bccno[x.u]=bcc_cnt;}
					if(bccno[x.v]!=bcc_cnt){bcc[bcc_cnt].push_back(x.v);bccno[x.v]=bcc_cnt;}
					if(x.u==u&&x.v==v)break;
				}
			}
		}
		else if(pre[v]<pre[u]&&v!=fa){
			S.push(e);
			lowu=min(lowu,pre[v]);
		}
	}
	if(fa<0&&child==1)iscut[u]=0;
	return lowu;
}

void find(int n){
	memset(pre,0,sizeof(pre));
	memset(iscut,0,sizeof(iscut));
	memset(bccno,0,sizeof(bccno));
	dfs_clock=bcc_cnt=0;
	for(int i=1;i<=n;++i){
		if(!pre[i])dfs(i,-1);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init();
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	find(n);
	for(int i=1;i<=n;++i){
		printf("%d:%d %d\n",i,iscut[i],bccno[i]);
	}
	for(int i=0;i<=bcc_cnt;++i){
		printf("%d:",i);
		for(int j=0;j<bcc[i].size();++j){
			printf("%d ",bcc[i][j]);
		}
		printf("\n");
	}
	return 0;
}
