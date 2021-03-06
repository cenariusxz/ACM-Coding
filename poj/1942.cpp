#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll getC(ll n,ll m){
	ll ans = 1;
	for(ll i = n, j = 1 ; j <= m ; -- i, ++ j){
		ans *= i;
		ans /= j;
	}
	return ans;
}

int main(){
	ll n,m;
	while(scanf("%lld%lld",&n,&m) == 2){
		if(!n && !m)break;
		if(n>m)swap(n,m);
		printf("%lld\n",getC(n+m,n));	
	}
	return 0;
}

