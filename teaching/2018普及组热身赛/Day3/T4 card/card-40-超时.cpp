#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll a[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 5 ; T <= 5 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-s1.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    ll ans = 0;
    while(1){
        ll id = 0;
        for(int i = 1 ; i <= n ; ++ i){
            if(a[i] >= a[id])id = i;
        }
        if(id == 1)break;
        a[1] ++;
        a[id] --;
        ans ++;
    }
    printf("%lld\n",ans);

    }
    return 0;
}
