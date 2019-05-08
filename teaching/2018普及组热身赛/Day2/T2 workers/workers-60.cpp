#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

int a[105][maxn];
int dp[105][maxn];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T2-") + ID[T] + "-s.out").c_str() ,"w",stdout);

    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            scanf("%d",&a[j][i]);
        }
        dp[1][i] = a[1][i];
    }
    for(int t = 2 ; t <= m ; ++ t){
        for(int i = 1 ; i <= n ; ++ i){
            dp[t][i] = a[t][i];
            for(int j = max(i-k,1) ; j < i ; ++ j){
                dp[t][i] += dp[t-1][j];
                if(dp[t][i] >= mod)dp[t][i] -= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i)ans = max(ans, dp[m][i]);
    printf("%d\n",ans);

    }
    return 0;
}
