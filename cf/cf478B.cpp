#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

ll get(ll x){return x*(x-1)/2;}

int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll k = n/m;
    ll p = n - k*m;
    ll ans1 = p*get(k+1) + (m-p)*get(k);
    ll ans2 = get(n-m+1);
    printf("%lld %lld\n",ans1,ans2);
	return 0;
}
