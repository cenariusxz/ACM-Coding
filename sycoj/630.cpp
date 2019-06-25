#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a,b;
bool f = 0;
ll ans[100005],que[100005],lim;

int gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}

void dfs(int k, ll a, ll b, int r){
    ll g = gcd(a,b);
    a /= g; b /= g;
    if(k == r - 1){
        if(a != 1 || b <= que[k])return;
        que[k+1] = b;
        if(b < lim){
            f = 1;
            for(int i = 1 ; i <= k+1 ; ++ i)ans[i] = que[i];
            lim = b;
        }
        return;
    }
    ll Left = max( b/a + (b%a != 0) , que[k] + 1);
    ll Right = min( b*(r-k)/a - (b*(r-k)%a == 0) , lim - 1);
    for(ll i = Left ; i <= Right ; ++ i){
        if(i >= lim)break;
        que[k+1] = i;
        dfs(k+1, a*i-b, b*i, r);
    }
}

int main(){
    scanf("%d%d",&a,&b);
    for(int i = 1 ; ; ++ i){
        lim = INF;
        dfs(0,a,b,i);
        if(f){
            for(int j = 1 ; j <= i ; ++ j){
                printf("%lld ",ans[j]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}

