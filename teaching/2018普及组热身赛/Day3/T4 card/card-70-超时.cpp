#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll a[maxn];
int n;
priority_queue<ll>q;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 8 ; T <= 8 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-s2.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    for(int i = 2 ; i <= n ; ++ i)q.push(a[i]);
    ll ans = 0;
    while(1){
        ll now = q.top(); q.pop();
        if(now < a[1])break;
        a[1] ++;
        now --;
        ans ++;
        q.push(now);
    }
    printf("%lld\n",ans);

    }
    return 0;
}
