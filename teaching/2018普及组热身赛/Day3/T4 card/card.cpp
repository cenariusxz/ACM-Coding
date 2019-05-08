#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll a[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
//    for(int T = 1 ; T <= 10 ; ++ T){
//    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
//    freopen( (string("T4-") + ID[T] + ".out").c_str() ,"w",stdout);

    scanf("%d",&n);
    n--;
    for(int i = 0 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    sort(a+1,a+1+n,greater<ll>());
    ll ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        ll tmp = i * (a[i] - a[i+1]);
        if(a[0] + tmp > a[i+1]){
            ll x = (a[i] - a[0])/(i+1);
            ans += a[i] - x + 1 - a[0];
            break;
        }
        ans += tmp;
        a[0] += tmp;
    }
    printf("%lld\n",ans);

//    }
    return 0;
}
