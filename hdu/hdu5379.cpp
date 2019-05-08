#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxm=1e5+5;
const int mod=1e9+7;

int head[maxm],nxt[maxm<<1],point[maxm<<1],size;
int son[maxm],leaf[maxm];
int lf[maxm];	//-1 未访问，0 叶，1 子,2 访问中
int fa[maxm];
ll c[maxm];
ll dp[maxm];

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int s){
	int i;
	lf[s]=2;
	for(i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(lf[j]==-1){
			fa[j]=s;
			if(dfs(j)==0)leaf[s]++;
			else son[s]++;
		}
	}
	if(son[s]==0&&leaf[s]==0){
		lf[s]=0;
		return 0;
	}
	lf[s]=1;
	return 1;
}

ll dfs2(int s){
	int i;
	if(son[s]>2){
		return 0;
	}
	if(lf[s]==0)return 1;
	ll t;
	if(son[s]==2)t=1;
	else t=2;
	for(i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(fa[j]==s&&lf[s]==1){
			t=(t*dfs2(j))%mod;
		}
	}
	t=(t*c[leaf[s]])%mod;
	dp[s]=t;
	return t;
}

void init(){
	c[0]=1;
	c[1]=1;
	for(int i=2;i<=100000;i++)c[i]=c[i-1]*i%mod;
}

int main(){
	init();
	int T=read();
	for(int q=1;q<=T;++q){
		int n=read();
		if(n==1){printf("Case #%d: 1\n",q);continue;}
		size=0;
		memset(head,-1,sizeof(head));
		memset(son,0,sizeof(son));
		memset(lf,-1,sizeof(lf));
		memset(leaf,0,sizeof(leaf));
		int i;
		for(i=1;i<n;++i){
			int a=read();
			int b=read();
			add(a,b);
		}
		memset(dp,0,sizeof(dp));
		dfs(1);
		printf("Case #%d: %lld\n",q,dfs2(1));
	}
	return 0;
}
