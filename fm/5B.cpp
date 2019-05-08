#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int mod=1e6+7;

int C[405][405];

void init(){
	for(int i=0;i<=400;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(i==0||j==0)?1:(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("Case %d: ",q);
		if(k>n*m){
			printf("0\n");
			continue;
		}
		ll ans=0;
		
		if(k<=n*(m-1)){
			ans=(ans+(2*C[n*(m-1)][k])%mod)%mod;
		}

		if(k<=(n-1)*m){
			ans=(ans+(2*C[(n-1)*m][k])%mod)%mod;
		}

		if(k<=n*(m-2)){
			ans=((ans-C[n*(m-2)][k])%mod+mod)%mod;
		}

		if(k<=(n-2)*m){
			ans=((ans-C[(n-2)*m][k])%mod+mod)%mod;
		}

		if(k<=(n-1)*(m-1)){
			ans=((ans-4*C[(n-1)*(m-1)][k])%mod+mod)%mod;
		}

		if(k<=(n-1)*(m-2)){
			ans=(ans+(2*C[(n-1)*(m-2)][k])%mod)%mod;
		}

		if(k<=(n-2)*(m-1)){
			ans=(ans+(2*C[(n-2)*(m-1)][k])%mod)%mod;
		}

		if(k<=(n-2)*(m-2)){
			ans=((ans-C[(n-2)*(m-2)][k])%mod+mod)%mod;
		}
		
		printf("%lld\n",((C[n*m][k]-ans)%mod+mod)%mod);
	}
	return 0;
}
