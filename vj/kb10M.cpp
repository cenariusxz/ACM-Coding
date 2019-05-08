#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=2005;
const int maxm=2005;
int match[maxn][maxm],g[maxn][maxm],cnt[maxm],lim,n,m;
bool vis[maxm];

bool dfs(int x){
	for(int i=0;i<m;i++){
		if(g[x][i]==0||vis[i]==1)continue;
		vis[i]=1;
		if(cnt[i]<lim){
			match[i][cnt[i]++]=x;
			return 1;
		}
		for(int j=0;j<lim;j++){
			if(dfs(match[i][j])==1){
				match[i][j]=x;
				return 1;
			}
		}
	}
	return 0;
}
bool hungary(int n){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)==0)return 0;
	}
	return 1;
}

char s[10000];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		getchar();
		if(n==0&&m==0)break;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++){
			gets(s);
			int len=strlen(s);
			for(int j=0;j<len;++j){
				if(s[j]>='0'&&s[j]<='9'){
					int tmp=0;
					while(s[j]>='0'&&s[j]<='9'){
						tmp=tmp*10+s[j]-'0';
						++j;
					}
					g[i][tmp]=1;
				}
			}
		}
		int l=0,r=n;
		int ans=0x3f3f3f3f;
		while(l<=r){
			lim=l+((r-l)>>1);
			if(hungary(n)){
				ans=min(ans,lim);
				r=lim-1;
			}
			else l=lim+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
