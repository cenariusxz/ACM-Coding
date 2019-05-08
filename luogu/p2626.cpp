#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1ll << 31;

ll f[50];

int main(){
	f[1] = 1;f[2] = 1;
	for(int i = 3 ; i <= 48 ; ++ i){
		f[i] = f[i-2] + f[i-1];
		f[i] %= mod;
	}
	int n,cnt = 0;
	scanf("%d",&n);
	ll ans = f[n];
	printf("%lld",ans);
	for(ll i = 2 ; i * i <= ans ; ++ i){
		if(ans % i)continue;
		while(ans % i == 0){
			if(cnt == 0)printf("=");
			else printf("*");
			printf("%lld",i);
			cnt++;
			ans /= i;
		}
	}
	if(ans > 1){
		if(cnt == 0)printf("=");
		else printf("*");
		printf("%lld",ans);
	}
	printf("\n");
	return 0;
}
