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
        ll need = x/3 + ((x%3) ? 1 : 0);
        if(b >= need){
            b -= need;
            c = need * 3;
            c -= x;
        }
        else{
            c = b * 3;
            b = 0;
            x -= c; c = 0;
            ans += x;
        }
    }
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
//    for(int T = 1 ; T <= 10 ; ++ T){
//    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
//    freopen( (string("T1-") + ID[T] + "-l.out").c_str() ,"w",stdout);
    freopen("T1-6.in","r",stdin);
    freopen("T1-6.out","w",stdout);
    int n;
    ans = 0;
    scanf("%lld%lld%lld%d",&a,&b,&c,&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%lld",&x);
        ll p = x;
        if(i & 1)solve1();
        else solve2();
//        printf("%d %lld %lld %lld %lld %lld\n",i,p,a,b,c,ans);
    }
    printf("%lld\n",ans);
//    }
    return 0;
}
