#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1005;
const int mod=1e9+7;

ll C[maxn][maxn];
int a[maxn];

void init(){
	for(int i=0;i<=1000;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(!i||!j)?1:(C[i-1][j]+C[i-1][j-1]);
			if(C[i][j]>mod)C[i][j]-=mod;
		}
	}
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	ll ans=1;
	int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=n;i>=1;--i){
		ans=(ans*C[sum-1][a[i]-1])%mod;
		sum-=a[i];
	}
	printf("%I64d\n",ans);
	return 0;
}
