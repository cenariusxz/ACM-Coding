#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

int a[105][maxn];
ll sum[maxn],dp[maxn];

ll getsum(int l,int r){
    if(l < 1)return sum[r];
    if(l > r)return 0;
    return ((sum[r] - sum[l-1])%mod + mod)%mod;
}

ll max(ll a, ll b){return a > b ? a : b;}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){

    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T2-") + ID[T] + ".out").c_str() ,"w",stdout);

    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            scanf("%d",&a[j][i]);
        }
        sum[i] = (sum[i-1] + a[1][i]) % mod;
    }
    for(int t = 2 ; t <= m ; ++ t){
        for(int i = 1 ; i <= n ; ++ i){
            dp[i] = (getsum(i-k, i-1) + a[t][i]) % mod;
        }
        for(int i = 1 ; i <= n ; ++ i)sum[i] = (sum[i-1] + dp[i]) % mod;
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; ++ i)ans = max(ans, dp[i]);
    printf("%lld\n",ans);

    }

    return 0;
}
