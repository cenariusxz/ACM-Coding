#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int c[10001][100];
int num[10005];
int a[100005];
int vis[10005];
ll l[100005],r[100005];

void init(){
	int i,j;
	num[1]=1;
	c[1][1]=1;
	for(i=1;i<=10000;i++){
		for(j=1;j<=i/2;j++){
			if(!(i%j))c[i][++num[i]]=j;
		}
		c[i][++num[i]]=i;
	}
}

int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			int cnt=0;
			for(j=1;j<=num[a[i]];j++){
				if(cnt<vis[c[a[i]][j]])cnt=vis[c[a[i]][j]];
			}
			vis[a[i]]=i;
			l[i]=cnt+1;
		}
		memset(vis,-1,sizeof(vis));
		for(i=n;i>=1;i--){
			int cnt=n+1;
			for(j=1;j<=num[a[i]];j++){
				if(vis[c[a[i]][j]]!=-1&&cnt>vis[c[a[i]][j]])cnt=vis[c[a[i]][j]];
			}
			vis[a[i]]=i;
			r[i]=cnt-1;
		}
		ll ans=0;
		for(i=1;i<=n;i++){
			ans=(ans+((i-l[i]+1)*(r[i]-i+1))%mod)%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
