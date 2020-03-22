#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int h,w;
int r[maxn], c[maxn];

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
	scanf("%d%d", &h, &w);
	for(int i = 1 ; i <= h ; ++ i)scanf("%d", &r[i]);
	for(int i = 1 ; i <= w ; ++ i)scanf("%d", &c[i]);
	ll num = 0;
	for(int i = 1 ; i <= h ; ++ i)num += min(r[i]+1, w);
	for(int j = 1 ; j <= w ; ++ j){
		for(int i = 1 ; i <= min(c[j]+1, h) ; ++ i){
			if(i <= c[j] && r[i] + 1 == j)num -= INF;
			if(i == c[j]+1 && r[i] >= j)num -= INF;
			if(r[i] + 1 < j)num ++;	
		}
	}
	if(num < 0)printf("0\n");
	else printf("%lld\n", QP(2, h*w-num));
	return 0;
}

