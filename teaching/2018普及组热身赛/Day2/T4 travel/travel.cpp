#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int dp[maxn];
int M[maxn][maxn];
int n,m;

void dfs(int s){
    for(int i = 1 ; i <= n ; ++ i){
        if(M[s][i]){
            if(!dp[i])dfs(i);
            dp[s] = max(dp[s],dp[i]);
        }
    }
    dp[s] ++;
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + ".out").c_str() ,"w",stdout);

    scanf("%d%d",&n,&m);
    memset(M,0,sizeof(M));
    for(int i = 1 ; i <= m ; ++ i){
        int a,b;
        scanf("%d%d",&a,&b);
        M[a][b] = 1;
    }
    memset(dp,0,sizeof(dp));
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        if(!dp[i])dfs(i);
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);

    }
    return 0;
}
