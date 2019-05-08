#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=100010;
const int maxm=11;
int match[maxn][maxm],g[maxn][maxm],cnt[maxm],lim[maxn],n,m;
bool vis[maxm];

bool dfs(int s){
	for(int i=0;i<m;++i){
		if(g[s][i]==0||vis[i]==1)continue;
		vis[i]=1;
		if(cnt[i]<lim[i]){
			match[i][cnt[i]++]=s;
			return 1;
		}
		else{
			for(int j=0;j<lim[i];++j){
				if(dfs(match[i][j])==1){
					match[i][j]=s;
					return 1;
				}
			}
		}
	}
	return 0;
}
bool hungary(int n){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;++i){
		memset(vis,0,sizeof(vis));
		if(dfs(i)==0)return 0;
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(g,0,sizeof(g));
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)scanf("%d",&g[i][j]);
		for(int i=0;i<m;++i)scanf("%d",&lim[i]);
		if(hungary(n))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
