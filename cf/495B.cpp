#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll a, b;
set<ll>S;

int solve(){
	ll num = a-b;
	int ans = 0;
	for(ll i = 1 ; i * i <= num ; ++ i){
		if(num % i == 0){
			if(i > b)S.insert(i);
			if(num/i > b)S.insert(num/i);
		}
	}
	return S.size();
}

int main(){
	scanf("%lld%lld", &a, &b);
	if(a < b)printf("0\n");
	if(a == b)printf("infinity\n");
	if(a > b)printf("%d\n", solve());
	return 0;
}


