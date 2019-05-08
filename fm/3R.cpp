#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

const int maxn=1605;
const int maxm=1e5;

char s[45][45];
int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int n,t,scccnt;
int stx[maxn],low[maxn],scc[maxn],num[maxn],v[maxn];
int dp[maxn];
stack<int>S;

int max(int a,int b){return a>b?a:b;}

void init(){
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
	memset(num,0,sizeof(num));
	memset(dp,-1,sizeof(dp));
}

void add(int a,int b,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
}

void dfs(int s){
	stx[s]=low[s]=++t;
	S.push(s);
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
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
			num[scccnt]+=v[u];
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
		for(int j=head[0][i];~j;j=nxt[0][j]){
			int k=point[0][j];
			if(scc[i]!=scc[k]){
				add(scc[i],scc[k],1);
			}
		}
	}
}

int Dp(int s){
	if(~dp[s])return dp[s];
	int maxx=0;
	for(int i=head[1][s];~i;i=nxt[1][i]){
		maxx=max(maxx,Dp(point[1][i]));
	}
	return dp[s]=num[s]+maxx;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,l;
		scanf("%d%d",&l,&m);
		n=m*l;
		init();
		for(int i=1;i<=l;++i)scanf("%s",s[i]+1);
		int a,b;
		for(int i=1;i<=l;++i){
			for(int j=1;j<=m;++j){
				int p=(i-1)*m+j;
				if(s[i][j]>='0'&&s[i][j]<='9'){
					v[p]=s[i][j]-'0';
				}
				else v[p]=0;
				if(s[i][j]!='#'){
					if(i+1<=l&&s[i+1][j]!='#'){
						add(p,p+m);
					}
					if(j+1<=m&&s[i][j+1]!='#'){
						add(p,p+1);
					}
				}
				if(s[i][j]=='*'){
					scanf("%d%d",&a,&b);
					a++;
					b++;
					if(s[a][b]!='#'){
						int p1=(a-1)*m+b;
						add(p,p1);
					}
				}
			}
		}
		setscc();
		printf("%d\n",Dp(scc[1]));
	}
	return 0;
}
