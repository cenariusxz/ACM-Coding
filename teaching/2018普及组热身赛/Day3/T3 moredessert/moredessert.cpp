#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int maxs = 1005;
const int INF = 0x3f3f3f3f;

ll a[maxn],b[maxn],c[maxn],s[maxn],sum[maxn];
ll dp[maxn][maxs];
int n;

ll min(ll a, ll b){return a < b ? a : b;}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
//    for(int T = 10 ; T <= 10 ; ++ T){
//    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
//    freopen( (string("T3-") + ID[T] + ".out").c_str() ,"w",stdout);

    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&b[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&c[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&s[i]);
    for(int i = n ; i >= 1 ; -- i)sum[i] = sum[i+1] + s[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 0 ; j <= sum[i+1] ; ++ j){
            for(int k = 0 ; k <= j + s[i] ; ++ k){
                dp[i][j] = min(dp[i][j], dp[i-1][k] + (s[i] + j - k) * (a[i] * k * k + b[i] * k + c[i]));
            }
        }
    }
    printf("%lld\n",dp[n][0]);

//    }
    return 0;
}
