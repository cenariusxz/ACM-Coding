#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e3+5;

int M[maxn][maxn];
ui f[maxn][maxn],x[maxn];
ui l[maxn][maxn],r[maxn][maxn],u[maxn][maxn],d[maxn][maxn];

void init(){
	for(int i=1;i<=1001;++i){
		x[i]=0;
		for(int k=0;k<i;++k){
			x[i]+=(ui)(i-k)*(ui)(k+1);
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=1000;++i){
		for(int j=1;j<=1000;++j){
			if(j==1)f[i][j]=x[i];
			else{
				f[i][j]=f[i][j-1]*(ui)2-f[i][j-2]+(ui)j*x[i];
			}
		}
	}
}

int st[maxn];

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&M[i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			int cnt=0;
			for(int j=1;j<=m;++j){
				while(cnt!=0){
					if(M[i][j]<M[i][st[cnt-1]])cnt--;
					else break;
				}
				if(cnt==0){
					l[i][j]=1;
					st[cnt++]=j;
				}
				else{
					l[i][j]=st[cnt-1]+1;
					st[cnt++]=j;
				}
			}
			cnt=0;
			for(int j=m;j>=1;--j){
				while(cnt!=0){
					if(M[i][j]<M[i][st[cnt-1]])cnt--;
					else break;
				}
				if(cnt==0){
					r[i][j]=m;
					st[cnt++]=j;
				}
				else{
					r[i][j]=st[cnt-1]-1;
					st[cnt++]=j;
				}
			}
		}
		for(int j=1;j<=m;++j){
			int cnt=0;
			for(int i=1;i<=n;++i){
				while(cnt!=0){
					if(M[i][j]>M[st[cnt-1]][j])cnt--;
					else break;
				}
				if(cnt==0){
					u[i][j]=1;
					st[cnt++]=i;
				}
				else{
					u[i][j]=st[cnt-1]+1;
					st[cnt++]=i;
				}
			}
			cnt=0;
			for(int i=n;i>=1;--i){
				while(cnt!=0){
					if(M[i][j]>M[st[cnt-1]][j])cnt--;
					else break;
				}
				if(cnt==0){
					d[i][j]=n;
					st[cnt++]=i;
				}
				else{
					d[i][j]=st[cnt-1]-1;
					st[cnt++]=i;
				}
			}
		}
		ui ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int uu=i-u[i][j],dd=d[i][j]-i,lll=j-l[i][j],rr=r[i][j]-j;
				ans+=(ui)M[i][j]*(f[uu+dd+1][lll+rr+1]-f[uu+dd+1][lll]-f[uu+dd+1][rr]-f[uu][lll+rr+1]-f[dd][lll+rr+1]+f[uu][lll]+f[uu][rr]+f[dd][lll]+f[dd][rr]);
			}
		}
		printf("%lld\n",(ll)ans);
	}
	return 0;
}
