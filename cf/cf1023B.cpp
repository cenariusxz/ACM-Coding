#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

ll n,k;

int main(){
    scanf("%lld%lld",&n,&k);
    ll left = k/2+1;
    if(n>=k)n=k-1;
    ll ans = 0;
    if(left <= n)ans = n-left+1;
    printf("%lld\n",ans);
	return 0;
}
