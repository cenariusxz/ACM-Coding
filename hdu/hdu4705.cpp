#pragma comment(linker, "/STACK:16777216")
#include<stdio.h>
#include<string.h>
typedef long long ll;
const int maxm=1e5+10;
int d[maxm],son[maxm],fa[maxm];
ll dp[maxm],Dp[maxm],sum,Sum;
int head[maxm],point[maxm<<1],nxt[maxm<<1],size;
int n;

inline void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs1(int r){
	for(int i=head[r];~i;i=nxt[i]){
		int j=point[i];
		if(!d[j]){
			d[j]=d[r]+1;
			fa[j]=r;
			son[r]+=dfs1(j);
		}
	}
	return son[r]+1;
}

ll dfs2(int r){
	for(int i=head[r];~i;i=nxt[i]){
		int j=point[i];
		if(d[j]==d[r]+1){
			dp[r]+=son[j]+dfs2(j);
		}
	}
	sum+=dp[r];
	return dp[r];
}

void dfs3(int r){
	Dp[r]=-son[r]-1+Dp[fa[r]]+dp[fa[r]]-dp[r]-son[r]+n-d[fa[r]];
	Sum+=Dp[r];
	for(int i=head[r];~i;i=nxt[i]){
		int j=point[i];
		if(d[j]==d[r]+1){
			dfs3(j);
		}
	}
}

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(son,0,sizeof(son));
		memset(head,-1,sizeof(head));
		size=0;
		memset(d,0,sizeof(d));
		memset(dp,0,sizeof(dp));
		memset(Dp,0,sizeof(Dp));
		sum=Sum=0;
		int i;
		for(i=1;i<=n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		d[1]=1;
		fa[1]=0;
		dfs1(1);
		son[0]=son[1]+1;
		dfs2(1);
		for(i=head[1];~i;i=nxt[i]){
			dfs3(point[i]);
		}
		ll ans=((ll)n*(n-1)*(n-2)/2/3)-sum-Sum/2;
		printf("%lld\n",ans);
	}
	return 0;}
