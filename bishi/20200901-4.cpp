#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[25];

inline ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;} 

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < m ; ++ i)scanf("%d", &a[i]);
	ll ans = 0;
	for(int sta = 1 ; sta < (1 << m) ; ++ sta){
		ll lcm = 1;
		int bits = 0;
		for(int i = 0 ; i < m ; ++ i){
			if(sta & (1 << i)){
				bits ^= 1;
				lcm = lcm / gcd(lcm, a[i]) * a[i];
			}
		}
		if(bits)ans += n / lcm;
		else ans -= n / lcm;
	}
	printf("%lld\n", ans);
	return 0;
}

