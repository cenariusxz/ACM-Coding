#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main(){
    ll n;
    scanf("%lld",&n);
    if(n % 2)printf("%lld\n",n/2-n);
    else printf("%lld\n",n/2);
	return 0;
}
