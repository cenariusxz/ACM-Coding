#include <bits/stdc++.h>
using namespace std;

int n,t[505];
int dp[2][505];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&t[i]);
    dp[0][1] = 1;
    for(int i = 2 ; i <= n ; ++ i){
        dp[0][i] = 1;
        for(int j = 1 ; j < i ; ++ j){
            if(t[j] < t[i])dp[0][i] = max(dp[0][i], dp[0][j]+1);
        }
    }
    dp[1][n] = 1;
    for(int i = n - 1 ; i >= 1 ; -- i){
        dp[1][i] = 1;
        for(int j = i +1 ; j <= n ; ++ j){
            if(t[j] < t[i])dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i)ans = max(ans, dp[0][i] + dp[1][i] - 1);
    printf("%d\n",n-ans);
    return 0;
}
