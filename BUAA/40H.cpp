#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=1100;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}


int a[maxn][maxn];
int Gcd[4][maxn][maxn];
int g[2][maxn][maxn];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(j==1)g[0][i][j]=a[i][j];
				else{
					g[0][i][j]=gcd(g[0][i][j-1],a[i][j]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=m;j>=1;--j){
				if(j==m)g[1][i][j]=a[i][j];
				else{
					g[1][i][j]=gcd(g[1][i][j+1],a[i][j]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(i==1)Gcd[0][i][j]=g[0][i][j];
				else Gcd[0][i][j]=gcd(Gcd[0][i-1][j],g[0][i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=m;j>=1;--j){
				if(i==1)Gcd[1][i][j]=g[1][i][j];
				else Gcd[1][i][j]=gcd(Gcd[1][i-1][j],g[1][i][j]);
			}
		}
//		printf("aaa\n");
		for(int i=n;i>=1;--i){
			for(int j=1;j<=m;++j){
//				printf("%d %d\n",i,j);
				if(i==n){
//					printf("%d %d\n",i,j);
					Gcd[2][i][j]=g[0][i][j];
				}
				else Gcd[2][i][j]=gcd(Gcd[2][i+1][j],g[0][i][j]);
//				printf("%d %d\n",i,j);
			}
		}
//		printf("aaa\n");
		for(int i=n;i>=1;--i){
			for(int j=m;j>=1;--j){
				if(i==n)Gcd[3][i][j]=g[1][i][j];
				else Gcd[3][i][j]=gcd(Gcd[3][i+1][j],g[1][i][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int gg;
				if(i==1&&j==1){
					gg=Gcd[3][i+1][j+1];
				}
				else if(i==1&&j>1&&j<m){
					gg=gcd(Gcd[2][i+1][j-1],Gcd[3][i+1][j+1]);
				}
				else if(i==1&&j==m){
					gg=Gcd[2][i+1][j-1];
				}
				else if(i>1&&i<n&&j==1){
					gg=gcd(Gcd[1][i-1][j+1],Gcd[3][i+1][j+1]);
				}
				else if(i>1&&i<n&&j>1&&j<m){
					gg=gcd(Gcd[0][i-1][j-1],gcd(Gcd[1][i-1][j+1],gcd(Gcd[2][i+1][j-1],Gcd[3][i+1][j+1])));
				}
				else if(i>1&&i<n&&j==m){
					gg=gcd(Gcd[0][i-1][j-1],Gcd[2][i+1][j-1]);
				}
				else if(i==n&&j==1){
					gg=Gcd[1][i-1][j+1];
				}
				else if(i==n&&j>1&&j<m){
					gg=gcd(Gcd[0][i-1][j-1],Gcd[1][i-1][j+1]);
				}
				else if(i==n&&j==m){
					gg=Gcd[0][i-1][j-1];
				}
				if(gg>ans)ans=gg;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
