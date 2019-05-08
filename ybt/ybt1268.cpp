#include <bits/stdc++.h>
using namespace std;

int n,m,w[50],c[50];
int dp[205];

int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&w[i],&c[i]);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = w[i] ; j <= m ; ++ j)dp[j] = max(dp[j], dp[j-w[i]] + c[i]);
    }
    int ans = 0;
    for(int i = 1 ; i <= m ; ++ i)ans = max(ans, dp[i]);
    printf("max=%d\n",ans);
    return 0;
}
