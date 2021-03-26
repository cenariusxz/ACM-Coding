#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b;
map<ll, ll> M;

ll min(ll x, ll y){return x < y ? x : y;}

ll dfs(ll x){
	if(M[x])return M[x];
	if(x % 2 == 0)return M[x] = dfs(x/2) + min(a, x/2*b);
	return M[x] = min(dfs(x+1), dfs(x-1)) + b;
}

int main(){
	scanf("%lld%lld%lld", &n, &a, &b);
	M[1] = b;
	printf("%lld\n", dfs(n));
	return 0;
}

