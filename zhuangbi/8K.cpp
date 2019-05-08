#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF=0x3f3f3f3f;

const int maxn=35;

int ma[maxn][maxn];
int dis[maxn][maxn];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		memset(ma,0x3f,sizeof(ma));
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(ma[a][b]>c)ma[a][b]=ma[b][a]=c;
		}
		int maxx=0;
		for(int q=2;q<n;++q){
			memcpy(dis,ma,sizeof(dis));
			for(int i=1;i<=n;++i)dis[i][q]=dis[q][i]=INF;
			for(int k=1;k<=n;++k){
				if(k==q)continue;
				for(int i=1;i<=n;++i){
					if(i==q)continue;
					for(int j=1;j<=n;++j){
						if(j==q)continue;
						if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
			if(dis[1][n]>maxx)maxx=dis[1][n];
		}
		if(maxx==INF)printf("Inf\n");
		else printf("%d\n",maxx);
	}
	return 0;
}
