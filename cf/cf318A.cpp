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
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k <= (n+1)/2)printf("%lld\n",2*k-1);
    else printf("%lld\n",(k-(n+1)/2)*2);
	return 0;
}
