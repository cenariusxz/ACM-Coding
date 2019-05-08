#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;


int n,m,w[3505],c[3505];
int dp[13005];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&w[i],&c[i]);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = m ; j >= w[i] ; -- j)dp[j] = max(dp[j], dp[j-w[i]] + c[i]);
    }
    int ans = 0;
    for(int i = 1 ; i <= m ; ++ i)ans = max(ans, dp[i]);
    printf("%d\n",ans);
    return 0;
}
