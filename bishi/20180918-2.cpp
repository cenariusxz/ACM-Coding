#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

ll dp[20],num[20],val[20],a[20];

int main(){
    num[0] = 1;
    for(int i = 1 ; i < 15 ; ++ i)num[i] = num[i-1] * 10;
    for(int i = 1 ; i < 15 ; ++ i)dp[i] += num[i-1] * i;
    int x, pos = 0;
    scanf("%d",&x);
    while(x){
        a[++pos] = x % 10;
        val[pos] = val[pos-1] * 10 + a[pos];
        x /= 10;
    }
    ll ans = 0;
    for(int i = pos ; i >= 1 ; -- i){
        ans += dp[i-1] * a[i];
        if(a[i] == 1)ans += val[i-1] + 1;
        if(a[i] > 1)ans += num[i-1];
    }
    printf("%lld\n",ans);
	return 0;
}
