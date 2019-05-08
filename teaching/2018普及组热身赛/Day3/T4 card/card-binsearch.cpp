#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[maxn];
int n;

ll min(ll a, ll b){return a < b ? a : b;}

bool check(ll num){
    ll a0 = a[0] + num;
    for(int i = 1 ; i <= n ; ++ i){
        ll tmp = i * (a[i] - a[i+1]);
        if(tmp >= num){
            ll x = num/i;
            return a0 > a[i]-x;
        }
        num -= tmp;
    }
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-bs.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    n--;
    for(int i = 0 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    sort(a+1,a+1+n,greater<ll>());
    ll sum = 0;
    for(int i = 1 ; i <= n ; ++ i)sum += a[i];
    ll ans = INF, l = 0 , r = sum;
    while(l <= r){
        ll mid = (l + r)>>1;
        if(check(mid)){
            ans = min(ans,mid);
            r =mid - 1;
        }
        else l = mid + 1;
    }
    printf("%lld\n",ans);

    }
    return 0;
}
