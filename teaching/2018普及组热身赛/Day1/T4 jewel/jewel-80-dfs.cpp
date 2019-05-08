#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int a[20][20],p[20],vis[20];
int n;
bool flag = false;
ll ans = 0, Max = 0;
clock_t tbegin;

void dfs(int s, ll sum){
    if(s == n){
        if(sum > ans)ans = sum;
        return;
    }
    if(sum + (n - s) * Max < ans)return;
    if((clock() - tbegin) / CLOCKS_PER_SEC > 0.94){
        flag = true;
        return;
    }
    for(int i = 0 ; i < n ; ++ i){
        if(vis[i])continue;
        vis[i] = 1;
        p[s+1] = i;
        dfs(s+1, sum + ( s ? a[p[s]][p[s+1]] : 0 ));
        if(flag)return;
        vis[i] = 0;
    }
}

int main(){
    tbegin = clock();
    freopen("T4-9.in","r",stdin);
    freopen("T4-9-d.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < n ; ++ j){
            scanf("%d",&a[i][j]);
            if(a[i][j] > Max)Max = a[i][j];
        }
    }
    dfs(0,0);
    printf("%lld\n",ans);
    return 0;
}
