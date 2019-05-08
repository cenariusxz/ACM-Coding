#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("T1-10.in","w",stdout);
    srand(time(NULL));
    ll a=rand(),b=1000000000000ll,c=rand();
    int n = 100000;
    ll lim = 1000000000000000ll/n + 1;
    printf("%lld %lld %lld %d\n",a,b,c,n);
    for(int i = 1 ; i <= n ; ++ i){
        ll ti = lim / 1000000000, num = 0;
        for(int j = 1 ; j <= ti ; ++ j)num += 1000000000 - rand()%100;
        printf("%lld ",num);
    }
    printf("\n");
    return 0;
}
