#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 998244353;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

int n, k, t, l[maxn], r[maxn], num[maxn];
int add[maxn], sub[maxn];
map<int, int>M;

ll A[maxn+5], AA[maxn+5];

ll QP(ll a, ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

void init(){
    A[0]=1;
    for(int i=1;i<=maxn;++i)A[i]=A[i-1]*i%mod;
    AA[maxn]=QP(A[maxn],mod-2);
    for(int i=maxn;i>=1;--i)AA[i-1]=AA[i]*i%mod;
}

ll C(int n,int m){
	if(m > n)return 0;
    return A[n] * AA[n-m] % mod * AA[m] % mod;
}

int main(){
	init();
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &l[i], &r[i]);
	for(int i = 1 ; i <= n ; ++ i)num[i] = l[i], num[n + i] = r[i];
	sort(num + 1 , num + 1 + 2*n);
	t = unique(num + 1 , num + 1 + 2*n) - (num + 1);
	for(int i = 1 ; i <= t ; ++ i)M[num[i]] = i;
	for(int i = 1 ; i <= n ; ++ i)add[M[l[i]]]++, sub[M[r[i]]]++;
	int sum = 0;
	ll ans = 0;
	for(int i = 1 ; i <= t ; ++ i){
		if(add[i]){
			ans += C(sum+add[i], k) - C(sum, k);
			ans = (ans % mod + mod) % mod;
			sum += add[i];
		}
		if(sub[i])sum -= sub[i];
	}
	printf("%lld\n", ans);
	return 0;
}

