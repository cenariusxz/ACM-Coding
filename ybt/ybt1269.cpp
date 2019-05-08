#include <bits/stdc++.h>
using namespace std;

int n,m,v[505],w[505],s[505];
int dp[6005];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d%d",&v[i],&w[i],&s[i]);
    for(int i = 1 ; i <= n ; ++ i){
        for(int k = 1 ; k <= s[i] ; ++ k){
            for(int j = m ; j >= v[i] ; -- j){
                dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= m ; ++ i)ans = max(ans, dp[i]);
    printf("%d\n",ans);
    return 0;
}
