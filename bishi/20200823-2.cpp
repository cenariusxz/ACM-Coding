#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll pow2[maxn];
int n, k, num[1005];

void init(){
	pow2[0] = 1;
    for(int i = 1 ; i <= 100000 ; ++ i)pow2[i] = pow2[i-1] * 2 % mod;
}

int main(){
	init();
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d", &a);
		num[a % k] ++;
	}
	ll ans = 1;
	for(int i = 0 ; i + i <= k ; ++ i){
		if(i == 0)ans = ans * (num[i] + 1) % mod;			// fix
		else if(i + i == k)ans = ans * (num[i] + 1) % mod;
		else ans = ans * (pow2[num[i]] + pow2[num[k-i]] - 1) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

