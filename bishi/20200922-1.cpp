#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;}

void solve(){
	int n, m;
	scanf("%d%d", &n ,&m);
	ll e1 = n/2, e2 = m/2;
	ll o1 = n-e1, o2 = m-e2;
	ll up = e1 * o2 + e2 * o1;
	ll down = n * (ll)m;
	if(up == 0)printf("0/1\n");
	else{
		ll g = gcd(up, down);
		printf("%lld/%lld\n", up/g, down/g);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

