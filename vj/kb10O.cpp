#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1005;
const int maxm=25;
int match[maxn][maxm],g[maxn][maxm],cnt[maxm],lim[maxn],n,m,b,mid;
int List[maxn][maxm];
bool vis[maxm];

bool dfs(int s){
	for(int i=0;i<m;++i){
		if(g[s][i]<b||g[s][i]>b+mid-1||vis[i]==1)continue;
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
bool check(){
	for(b=0;b+mid-1<m;++b){
		if(hungary(n))return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			scanf("%d",&List[i][j]);
			List[i][j]--;
		}
	for(int i=0;i<m;++i)scanf("%d",&lim[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			g[i][List[i][j]]=j;
	int l=1,r=m;
	int ans=0x3f3f3f3f;
	while(l<=r){
		mid=l+((r-l)>>1);
		if(check()){
			ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
