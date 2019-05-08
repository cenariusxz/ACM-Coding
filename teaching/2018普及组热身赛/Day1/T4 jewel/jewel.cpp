#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll dp[maxn][20];
int a[20][20];

inline ll max(ll a, ll b){return a > b ? a : b;}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-l.out").c_str() ,"w",stdout);
//    freopen("T4-10.in","r",stdin);
//    freopen("T4-10-n.out","w",stdout);
    int n;
    ll ans = 0;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < n ; ++ j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int s = 1 ; s < (1 << n) ; ++ s){
        for(int i = 0 ; i < n ;  ++ i){
            if(! (s & (1 << i)))continue;
            int u = s - (1 << i);
            if(u == 0){
                dp[s][i] = 0;
                continue;
            }
            for(int j = 0 ; j < n ; ++ j){
                if(!(u & (1 << j)))continue;
                dp[s][i] = max(dp[s][i], dp[u][j] + a[i][j]);
            }
        }
    }
    for(int i = 0 ; i < n ; ++ i)ans = max(ans, dp[(1<<n)-1][i]);
    printf("%lld\n",ans);
    }
    return 0;
}
