#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int dp[maxn],id[maxn];
int M[maxn][maxn];
int n,m;

void topo(){
    int sum = 0;
    queue<int>q;
    for(int i = 1 ; i <= n ; ++ i){
        if(!id[i])q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        sum++;
        dp[u] ++;
        for(int i = 1 ; i <= n ; ++ i){
            if(M[u][i]){
                dp[i] = max(dp[i],dp[u]);
                id[i]--;
                if(!id[i])q.push(i);
            }
        }
    }
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-topo.out").c_str() ,"w",stdout);

    scanf("%d%d",&n,&m);
    memset(M,0,sizeof(M));
    for(int i = 1 ; i <= m ; ++ i){
        int a,b;
        scanf("%d%d",&a,&b);
        id[b] ++;
        M[a][b] = 1;
    }
    memset(dp,0,sizeof(dp));
    topo();
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i)ans = max(ans,dp[i]);
    printf("%d\n",ans);

    }
    return 0;
}
