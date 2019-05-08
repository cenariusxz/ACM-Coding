#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

ll a[maxn],s[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 8 ; T <= 10 ; ++ T){
    freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T2-") + ID[T] + "-s.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&s[i]);
    ll ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        ll tmp = INF;
        for(int j = 1 ; j <= i ; ++ j){
            if(a[j] < tmp)tmp = a[j];
        }
        ans += s[i] * tmp;
    }
    printf("%lld\n",ans);

    }
    return 0;
}
