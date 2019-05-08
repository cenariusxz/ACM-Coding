#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[35];
ll dp[35];
ll num1[35],num2[35];
ll dfs(int pos, bool limit){     //正在枚举第pos位，此时第pos位是否有上限
    if(pos == 0)return 0;
    if(!limit && dp[pos]!=-1) return dp[pos];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i){
        ans+=dfs(pos-1,limit && i==a[pos]);
        if( i == 1 )ans += (limit && a[pos] == 1) ? num2[pos-1]+1 : num1[pos-1];
    }
    if(!limit)dp[pos]=ans;
    return ans;
}
ll solve(int x){
    int pos=0;
    while(x){
        a[++pos] = x%10;
        num2[pos] = num2[pos-1] * 10 + a[pos];
        x /= 10;
    }
    return dfs(pos,true);
}
void init(){
    num1[0] = 1;
    for(int i = 1 ; i <= 10 ; ++ i)num1[i] = num1[i-1] * 10;
}
int main(){
    init();
    int x;
    while(scanf("%lld",&x)!=EOF){
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(x));
    }
    return 0;
}
