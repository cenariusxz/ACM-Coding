#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int dp[12][2][2][15];
bool vis[12][2][2][15];
int num[12];
int n;

int dfs(int t, int n13, int n1, int m, int flag){
    if(t == 0){
        if(n13 && m == 0)return 1;
        else return 0;
    }
    if(!flag && vis[t][n13][n1][m])return dp[t][n13][n1][m];
    int l = 0, r = flag ? num[t] : 9;
    int ans = 0;
    for(int i = l ; i <= r ; ++ i){
        ans += dfs(t-1, n13 || (n1 && i==3), i == 1, (m*10 + i) % 13,flag && i == r);
    }
    if(!flag)vis[t][n13][n1][m] = 1, dp[t][n13][n1][m] = ans;
    return ans;
}

int main(){
    while(scanf("%d",&n) != EOF){
        int cnt = 0;
        while(n){
            num[++cnt] = n % 10;
            n /= 10;
        }
        printf("%d\n",dfs(cnt, 0, 0, 0, 1));
    }
    return 0;
}
