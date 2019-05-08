#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=772002;
const int maxn=1e5+5;

vector<int>v[700];
ll A[700][700],C[700][700];
char s[30][30];
int num[30][30];
int head[700],point[625<<2],nxt[625<<2],size;
int c[700];
int fa[700],id[700],vis[700];
int xx[8]={-1,-1,-1,0,0,1,1,1};
int yy[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
int vis2[700];

inline void init(){
	for(int i=1;i<=625;++i){
		A[i][0]=1;
		A[i][1]=i;
		for(int j=2;j<=i;++j){
			A[i][j]=A[i][j-1]*(i-j+1)%mod;
		}
	}
	for(int i=0;i<=625;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:((C[i-1][j]+C[i-1][j-1])%mod);
		}
	}
//	ll ans=1;
//	for(int i=1;i<=25;++i)ans=ans*i%mod;
}

inline void Pre(){
	for(int i=1;i<=n*m;++i){fa[i]=i;c[i]=1;}
	memset(id,0,sizeof(id));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	size=0;
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			num[i][j]=++cnt;
		}
	}
}

inline void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline void uni(int x,int y){
	int X=find(x),Y=find(y);
	if(X!=Y){
		fa[X]=Y;
		c[Y]+=c[X];
	}
}

ll dfs(int s,int num,int sz){
	if(s==v[num].size()+1)return 1;
	ll ans=0;
	for(int i=0;i<v[num].size();++i){
		if(!vis2[i]){
			ll res=1;
			int tmp=0;
			vis2[i]=1;
			int ind=v[num][i];
			for(int j=head[ind];~j;j=nxt[j]){
				int k=point[j];
				id[k]--;
				if(!id[k])tmp++;
			}
			res=res*A[sz-1][tmp]%mod*dfs(s+1,num,sz-1-tmp)%mod;
			ans=(ans+res)%mod;
			for(int j=head[ind];~j;j=nxt[j]){
				int k=point[j];
				id[k]++;
			}
			vis2[i]=0;
		}
	}
	return ans;
}

int main(){
	init();
	int cnt=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		Pre();
		bool f=0;
		for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
				if(s[i][j]=='X'){
					vis[num[i][j]]=1;
					v[num[i][j]].clear();
					for(int k=0;k<8;++k){
						int dx=i+xx[k],dy=j+yy[k];
						if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
							if(s[dx][dy]=='X')f=1;
							uni(num[dx][dy],num[i][j]);
							add(num[i][j],num[dx][dy]);
						}
					}
				}
			}
		}
		printf("Case #%d: ",++cnt);
		if(f){printf("0\n");continue;}
		int tmp=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(!vis[num[i][j]]){
					if(find(num[i][j])==num[i][j])tmp++;
				}
				else{
					v[find(num[i][j])].push_back(num[i][j]);
				}
			}
		}
		ll ans=A[n*m][tmp];
		int sz=n*m-tmp;
		for(int i=1;i<=n*m;++i){
			if(vis[i]&&find(i)==i){
				memset(vis2,0,sizeof(vis2));
				ans=ans*dfs(1,i,c[i])%mod*C[sz][c[i]]%mod;
				sz-=c[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
