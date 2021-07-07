#include<stdio.h>
#include<string.h>

const int maxn=305;
const int INF=0x3f3f3f3f;
int g[maxn][maxn],n,m, q[maxn];

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

int main(){
	scanf("%d%d", &n, &m);
	memset(g,0x3f,sizeof(g));
	for(int i = 1 ; i <= m ; ++ i){
		int num;
		scanf("%d", &num);
		for(int j = 1 ; j <= num ; ++ j)scanf("%d", &q[j]);
		for(int j = 1 ; j <= num ; ++ j){
			for(int k = j + 1 ; k <= num ; ++ k){
				g[q[j]][q[k]] = g[q[k]][q[j]] = 1;
			}
		}
	}
	for(int k=1;k<=n;++k){
	    for(int i=1;i<=n;++i){
	        for(int j=1;j<=n;++j){
	            g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
	        }
	    }
	}
	int ans = INF;
	for(int i = 1 ; i <= n ; ++ i){
		int tmp = 0;
		for(int j = 1 ; j <= n ; ++ j){
			if(j == i)continue;
			tmp += g[i][j];
		}
		ans = min(ans, tmp*100/(n-1));
	}
	printf("%d\n", ans);
	return 0;
}
