#include<stdio.h>
#include<math.h>
typedef long long ll;

const int mod=1e9+7;

ll C[105][105];

void init(){
	for(int i=0;i<=100;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%lld\n",C[n][m]);
	}
	return 0;
}
