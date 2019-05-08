#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=10005;
const int maxm=50005;

int head[maxn],point[maxm],nxt[maxm],size;
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],od[maxn];
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(od,0,sizeof(od));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s){
	stx[s]=low[s]=++t;
	S.push(s);
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!stx[j]){
			dfs(j);
			low[s]=min(low[s],low[j]);
		}
		else if(!scc[j]){
			low[s]=min(low[s],stx[j]);
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
		for(int j=head[i];~j;j=nxt[j]){
			int k=point[j];
			if(scc[i]!=scc[k]){
				od[scc[i]]++;
			}
		}
	}
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
	init();
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	setscc();
	int ans=0;
	if(scccnt==1)printf("%d\n",n);
	else{
		for(int i=1;i<=scccnt;++i)if(!od[i])ans++;
		if(ans!=1){
			printf("0\n");
		}
		else{
			ans=0;
			for(int i=1;i<=n;++i){
				if(!od[scc[i]])ans++;
			}
			printf("%d\n",ans);
		}
	}
	}
	return 0;
}
