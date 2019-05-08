#include<stdio.h>
#include<string.h>

const int maxn=105;
const int INF=0x3f3f3f3f;
int ma[maxn][maxn],n;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}



memset(g,0x3f,sizeof(g));
for(int k=1;k<=n;++k){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
}
