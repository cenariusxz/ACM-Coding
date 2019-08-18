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

ll gcd(ll a, ll b){return b ? gcd(b, a%b) : a;}

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld/%lld\n",a/gcd(a,b),b/gcd(a,b));
	return 0;
}

