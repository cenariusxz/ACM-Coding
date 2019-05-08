#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll a,b,c,x,ans = 0;

void solve1(){
    if(a >= x)a -= x;
    else{
        x -= a; a = 0;
        if(b >= x)b -= x;
        else{
            x -= b; b = 0;
            if(c >= x)c -= x;
            else{
                x -= c; c = 0;
                ans += x;
            }
        }
    }
}

void solve2(){
    if(c >= x)c -= x;
    else{
        x -= c; c = 0;
        while(b && x){
            b --; c += 3;
            if(c >= x){
                c -= x; x = 0;
            }
            else{
                x -= c; c = 0;
            }
        }
        ans += x;
    }
}

int main(){
    freopen("T1-10.in","r",stdin);
    freopen("T1-10-s.out","w",stdout);
    int n;
    scanf("%lld%lld%lld%d",&a,&b,&c,&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%lld",&x);
        if(i & 1)solve1();
        else solve2();
    }
    printf("%lld\n",ans);
    return 0;
}
