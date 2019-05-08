#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 1010;
const int MAX_LOG = 10;

int n,m,first[MAXN],ecnt,root;
int fa[11][MAXN],dep[MAXN];

struct edge{
    int v,next;
}e[MAXN * MAXN];

void Add_edge(int u,int v){
    e[++ecnt].next = first[u];
    e[ecnt].v = v;
    first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
    fa[0][p] = pre;
    dep[p] = d;
    for(int i = first[p]; ~i; i = e[i].next){
        int v = e[i].v;
        if(v == pre) continue;
        Dfs(v,p,d + 1);
    }
}

void Init(){
    Dfs(root,-1,0);
    for(int k = 0; k + 1 < MAX_LOG; ++k){
        for(int i = 1; i <= n; ++i){
            if(fa[k][i] < 0) fa[k + 1][i] = -1;
            else fa[k + 1][i] = fa[k][fa[k][i]];
        }
    }
}

int Lca(int u,int v){
    if(dep[u] > dep[v]) swap(u,v);
    for(int k = 0; k < MAX_LOG; ++k){
        if((dep[v] - dep[u]) & (1 << k))
            v = fa[k][v];
    }
    if(u == v){
        return u;
    }
    for(int k = MAX_LOG - 1; k >= 0; --k){
        if(fa[k][u] != fa[k][v]){
            u = fa[k][u];
            v = fa[k][v];
        }
    }
	return fa[0][u];
}

ll value[11];
int llca[15][15][15];
bool ff[15];

int main(){
    char c;
    int a,b,k,i,j,p;
	scanf("%d",&n);
	memset(first,-1,sizeof(first));
	memset(llca,0,sizeof(llca));
	ecnt = 0;
	for(i=1;i<=n;i++)scanf("%lld",&value[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		Add_edge(a,b);
	}
	root=1;
	Init();
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			llca[Lca(i,j)][i][j]=1;
		}
	}
	int cc=11;
	int ans=0;
	for(i=1;i<(1<<n);i++){
		memset(ff,0,sizeof(ff));
		int num=0;
		for(j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				ff[j]=1;
				num++;
			}
		}
		bool f1=1;
		for(j=1;j<=n;j++){
			int cnt=0;
			for(k=1;k<=n;k++){
				for(p=k+1;p<=n;p++){
					if(llca[j][k][p]&&(ff[k]&&ff[p])){
				//		if(i==3&&j==1)printf("%d %d %d %d\n",k,ff[k],p,ff[p]);
						cnt++;
					}
				}
			}
	//		if(i==3&&j==1)printf("aa%d %lld\n",cnt,value[1]);
			if(cnt<value[j]){
/*				if(i==27){
					printf("%d %d\n",cnt,j);
				}
*/				f1=0;
				break;
			}
		}
		if(f1&&num<cc){
/*			if(num==2){
				printf("%d %d\n",cc,i);
				for(j=1;j<=n;j++)printf("%d ",ff[j]);
				printf("\n");
			}
*/			cc=num;
			ans=i;
		}
	}
	if(cc==11)printf("-1\n");
	else{
		printf("%d\n",cc);
		int ccnt=0;
		for(i=1;i<=n;i++){
			if(ans&(1<<(i-1))){
				if(ccnt)printf(" ");
				printf("%d",i);
				ccnt++;

			}
		}
		printf("\n");
	}
    return 0;
}
