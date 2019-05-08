#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[20][20];
int p[20];

int main(){
    clock_t tbegin = clock();
    freopen("T4-10.in","r",stdin);
    freopen("T4-10-r.out","w",stdout);
    int n;
    ll ans = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < n ; ++ j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0 ; i < n ; ++ i)p[i] = i;
    for(int i = 1 ; i < n ; ++ i)ans += a[p[i-1]][p[i]];
    while(1){
        random_shuffle(p, p+n);
        ll tmp = 0;
        for(int i = 1 ; i < n ; ++ i)tmp += a[p[i-1]][p[i]];
        if(tmp > ans)ans = tmp;
        if((double)(clock() - tbegin)/CLOCKS_PER_SEC > 0.96)break;
    }
    printf("%lld\n",ans);
    return 0;
}
