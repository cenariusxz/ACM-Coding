#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e5 + 3;

ll m,n;

ll QP(ll a, ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

int main(){
	scanf("%lld%lld",&m,&n);
	m %= mod;
	printf("%lld\n", ((QP(m, n) - m * QP((m-1+mod)%mod, n-1) % mod)%mod + mod)%mod );
	return 0;
}

