#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod=1e9+7;
long long dp[2][30];
char s[1000005];
int n,len,a[30],mark[100005];
bool vis[30];

int main(){
    int cas=0;
    int T;
    scanf("%d",&T);
    while(T--){
        

        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)dp[0][i]=1;
        t=0;
        int tmp=0;
        for(int i=0;i<len;i++){
            if (mark[i])
            {
                tmp = mark[i];
                int now = tmp&1, las = now^1;
                for (int j = 0; j < n; j ++)
                {
                    if (!vis[j])
                    {
                        dp[now][int(s[i])] += dp[las][j];
                    }
                }
                dp[now][int(s[i])] %= MOD;
            }
            if (!vis[int(s[i])])
            {
                vis[int(s[i])] = 1;
                t ++;
                if (t == n)
                {
                    memset(dp[(tmp&1)^1], 0, sizeof(dp[(tmp&1)^1]));
                    memset(vis, 0, sizeof(vis));
                    t = 0;
                }
            }
        }
        int ans2 = 0;
        for (int i = 0; i < n; i ++)
        {
            if (!vis[i])
            {
                ans2 += dp[ans&1][i];
                if (ans2 >= MOD) ans2 -= MOD;
            }
        }
        printf("%d\n", ans2);
    }
    return 0;
}
