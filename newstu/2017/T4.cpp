#include <stdio.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

ll a[maxn],sum1[maxn],sum2[maxn];

int main(){
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lld",&a[i]);
		sum1[i] = sum1[i-1] + a[i];
		sum2[i] = sum2[i-1] + i * a[i];
	}
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%lld\n", sum2[r] - sum2[l-1] - (sum1[r] - sum1[l-1]) * (l-1));
	}
	return 0;
}
