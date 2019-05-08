#include<stdio.h>
#include<string.h>
typedef long long ll;

const int maxn=1e3+5;

int a[maxn][maxn];
ll s[maxn][maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&a[i][j]);
			}
		}
		memset(s,0,sizeof(s));
		s[n][m]=a[n][m];
		ll ans=s[n][m];
		for(int i=m-1;i>=1;--i){
			s[n][i]=a[n][i]+s[n][i+1];
			if(s[n][i]>ans)ans=s[n][i];
		}
		for(int i=n-1;i>=1;--i){
			s[i][m]=a[i][m]+s[i+1][m];
			if(s[i][m]>ans)ans=s[i][m];
		}
		for(int i=n-1;i>=1;--i){
			for(int j=m-1;j>=1;--j){
				s[i][j]=s[i+1][j]+s[i][j+1]-s[i+1][j+1]+a[i][j];
				if(s[i][j]>ans)ans=s[i][j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
