#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;       //物品总数
const int maxm = 1005;      //背包容量（总质量）

//int dp[maxn][maxm];         //dp[i][j]表示：考虑完第[i]个物品，每个物品允许取或不取，占用 j 的重量，能够装的最大价值
int dp[maxm];
int n,m;
int v[maxn],w[maxn];        //每个钻石重w[i],价值v[i]

int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&w[i],&v[i]);
    int ans = 0;

    for(int i =  1 ; i <= n ; ++ i){        // 考虑第i个钻石
        for(int j = m ; j >= w[i] ; -- j){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);       //放入第i个钻石之后重量为j，那么放之前重量为j-w[i]，所以用考虑完i-1个钻石，达到 j-w[i] 重量的dp[i-1][j-w[i]] 加上第 i 个物品的价值v[i]，来更新dp[i][j];
        }
    }


    printf("%d\n",dp[m]);
    return 0;
}
