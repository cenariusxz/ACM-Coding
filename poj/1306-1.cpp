#include <stdio.h>
#include <algorithm>
#include <iostream>
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
	while(scanf("%lld%lld",&n,&m)){
		if(n == 0 && m == 0)break;
		printf("%lld things taken %lld at a time is ",n,m);
		if(m > n - m)m = n - m;
		printf("%lld",getC(n,m));
		printf(" exactly.\n");
	}
	return 0;
}

