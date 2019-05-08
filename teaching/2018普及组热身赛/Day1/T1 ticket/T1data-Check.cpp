#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll a,b,c,x,ans = 0;

int main(){
    freopen("T1-10.in","r",stdin);
    freopen("T1-10-c.out","w",stdout);
    int n;
    scanf("%lld%lld%lld%d",&a,&b,&c,&n);
    /*
    if( a < 1 || a > 1000000000000ll || b < 1 || b > 1000000000000ll || c < 1 || c > 1000000000000ll || n < 1 || n > 100000)printf("NO\n");
    ll sum = 0;
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%lld",&x);
        if(x < 1)printf("NO\n");
        sum += x;
    }
    if(sum > 1000000000000000ll)printf("NO\n");
    printf("AC\n");*/
    while(scanf("%lld",&x)!=EOF){
        n--;
    }
    if(n != 0)printf("WA!\n");
    printf("AC\n");
    return 0;
}
