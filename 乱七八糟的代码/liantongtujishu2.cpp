#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=11;
const int maxm=11;
const int mod=1e9+7;

ll C[maxn][maxn];		//组合数
ll F[maxn][maxm][105],G[maxn][maxm][105],H[maxn][maxm][105];

void init(){
	memset(H,0,sizeof(H));
	memset(F,0,sizeof(F));
	memset(G,0,sizeof(G));
	for(int i=0;i<200;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i&&j)?(C[i-1][j]+C[i-1][j-1])%mod:1;
		}
	}
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxm;++j){
			for(int k=0;k<=i*j;++k){
				H[i][j][k]=C[i*j][k];
			}
		}
	}
	F[0][0][0]=F[1][0][0]=F[1][0][0]=1;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=2;++j){
			for(int p=0;p<=i*j;++p){
				G[i][j][p]=0;
				for(int k1=1;k1<=i;++k1){
					for(int k2=0;k2<=j;++k2){
						if(k1==i&&k2==j)continue;
						for(int k3=0;k3<=min(k1*k2,p);++k3){
							G[i][j][p]+=C[i-1][k1-1]*C[j][k2]%mod*F[k1][k2][k3]%mod*H[i-k1][j-k2][p-k3]%mod;
							G[i][j][p]%=mod;
						}
					}
				}
				F[i][j][p]=((H[i][j][p]-G[i][j][p])%mod+mod)%mod;
			}
		}
	}
}

int main(){
	init();
	return 0;
}
