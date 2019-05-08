#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1005;
const int maxm=1005;
int match[maxn][maxm],g[maxn][maxm],cnt[maxm],lim,n,m,mid;
int dis[maxn][maxn];
bool vis[maxm];

bool dfs(int s){
	for(int i=0;i<m;++i){
		if(g[s][i]>mid||vis[i]==1)continue;
		vis[i]=1;
		if(cnt[i]<lim){
			match[i][cnt[i]++]=s;
			return 1;
		}
		else{
			for(int j=0;j<lim;++j){
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
	scanf("%d%d%d",&m,&n,&lim);
	for(int i=0;i<m+n;++i){
		for(int j=0;j<m+n;++j){
			scanf("%d",&dis[i][j]);
			if(i!=j&&dis[i][j]==0)dis[i][j]=20000;
		}
	}
	for(int k=0;k<n+m;++k){
		for(int i=0;i<n+m;++i){
			for(int j=0;j<n+m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			g[i][j]=dis[m+i][j];
		}
	}
	int l=0,r=20000;
	int ans=0x3f3f3f3f;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(hungary(n)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
