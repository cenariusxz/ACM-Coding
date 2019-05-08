#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int maxn=5e5+5;

vector<pii >v[maxn];
vector<int>d[maxn];
int ans[maxn];

int c[maxn][26];
int stx[maxn],edx[maxn];
int cnt=0;
int head[maxn],point[maxn<<1],nxt[maxn<<1],size=0;
char s[maxn];
int str[maxn],dep[maxn];
int n,m;

inline void init(){
	memset(head,-1,sizeof(head));
}

inline int lowbit(int x){return x&(-x);}

inline void cadd(int x,int id){
	for(int i=x;i<=cnt;i+=lowbit(i))c[i][id]++;
}

inline void csub(int x,int id){
	for(int i=x;i<=cnt;i+=lowbit(i))c[i][id]--;
}

inline int sum(int x,int id){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i][id];
	return ans;
}

inline void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int s,int fa,int d){
	stx[s]=++cnt;
	dep[s]=d;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j!=fa)dfs(j,s,d+1);
	}
	edx[s]=cnt;
}

void solve(){
	for(int Dep=1;Dep<=n&&d[Dep].size();++Dep){
		for(int i=0;i<d[Dep-1].size();++i){
			int s=d[Dep-1][i];
			csub(stx[s],str[s]);
//			update(1,1,cnt,stx[s],-1,str[s]);
		}
		for(int i=0;i<d[Dep].size();++i){
			int s=d[Dep][i];
			cadd(stx[s],str[s]);
//			update(1,1,cnt,stx[s],1,str[s]);
		}
		for(int i=0;i<v[Dep].size();++i){
			pii u=v[Dep][i];
			int s=u.se,id=u.fi;
			int num=0;
			for(int j=0;j<26;++j){
//				int tmp=query(1,1,cnt,stx[s],edx[s],j);
				int tmp=sum(edx[s],j)-sum(stx[s]-1,j);
				if(tmp%2)num++;
			}
			if(num>1)ans[id]=1;
		}
	}
	for(int i=1;i<=m;++i){
		if(!ans[i])printf("Yes\n");
		else printf("No\n");
	}
}

int main(){
	init();
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i){
		int fa;
		scanf("%d",&fa);
		add(i,fa);add(fa,i);
	}
	scanf("%s",s);
	for(int i=1;i<=n;++i)str[i]=s[i-1]-'a';
	dfs(1,-1,1);
	for(int i=1;i<=n;++i)d[dep[i]].pb(i);
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		v[b].pb(mp(i,a));
	}
	solve();
	return 0;
}
