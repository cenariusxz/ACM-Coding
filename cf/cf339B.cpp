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
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll p = 1, ans = 0;
    while(m--){
        ll a;
        scanf("%lld",&a);
        if(a >= p)ans += a-p;
        else ans += a + n - p;
        p = a;
    }
    printf("%lld\n",ans);
    return 0;
}
