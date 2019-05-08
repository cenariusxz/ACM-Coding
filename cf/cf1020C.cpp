#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 +5;
const ll INF = 1e60;

int C[maxn][maxn];
int n,m;
int que[maxn],qcnt;

ll solve(int num){
    qcnt = 0;
    int cnt = C[1][0] + num;
    ll ans = 0;
    for(int i = 2 ; i <= m ; ++ i){
        int icnt = C[i][0];
        for(int j = 1 ; j <= C[i][0] ; ++ j){
            if(icnt >= cnt){
                if(num == 0)return INF;
                ans += C[i][j];
                icnt--;
                num--;
            }
            else que[++qcnt] = C[i][j];
        }
    }
    if(qcnt < num)return INF;
    sort(que + 1 , que + 1 + qcnt);
    for(int i = 1 ; i <= num ; ++ i)ans+=que[i];
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1 ; i <= n ; ++ i){
        int p,c;
        scanf("%d%d",&p,&c);
        C[p][0] ++;
        C[p][ C[p][0] ] = c;
    }
    for(int i = 1 ; i <= m ; ++ i){
        if(!C[i][0])continue;
        sort(C[i] +1 , C[i] + 1 + C[i][0]);
    }
    ll ans = INF;
    for(int i = 0 ; i <= n ; ++ i){
        ans = min(ans,solve(i));
    }
    printf("%lld\n",ans);
    return 0;
}
