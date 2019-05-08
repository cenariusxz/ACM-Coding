#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e3 + 5;

ll QP(ll a,ll n){
    ll tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ans;
}

map<int,int>M;
int n;
int p[maxn],a[maxn],b[maxn];
ll dp[maxn][maxn];
ll sum[maxn][maxn];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d%d",&p[i],&a[i]);
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    int cnt = unique(b+1,b+n+1) - (b+1);
    for(int i = 1 ; i <= cnt ; ++ i)M[b[i]] = i;
    for(int i = 1 ; i <= n ; ++ i)a[i] = M[a[i]];
	dp[0][0] = 100;
	sum[0][0] = 100;
	for(int i = 1 ; i <= cnt ; ++ i)sum[0][i] += sum[0][i-1];
	for(int i = 1 ; i <= n ; ++ i){
        for(int j = 0 ; j < a[i] ; ++ j)dp[i][j] = dp[i-1][j] * (100 - p[i]) % mod;
        for(int j = a[i]+1 ; j <= cnt ; ++ j)dp[i][j] = dp[i-1][j] * 100 % mod;
        dp[i][a[i]] = (sum[i-1][a[i]-1] * p[i] % mod + dp[i-1][a[i]] * 100 % mod) % mod;
        sum[i][0] = dp[i][0];
        for(int j = 1 ; j <= cnt ; ++ j)sum[i][j] = sum[i][j-1] + dp[i][j];
	}
	ll tmp = 100, res = 0;
	for(int i = 1 ; i <= n ; ++ i){
        tmp = tmp * 100 % mod;
        res += sum[i-1][a[i]-1] * p[i] % mod * QP(tmp,mod-2) % mod;
        res %= mod;
	}
	printf("%lld\n",res);
	return 0;
}
