#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[maxn],b[maxn];

int main(){
    freopen("T3-10.in","r",stdin);
    freopen("T3-10-s.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&b[i]);
    ll res = INF;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = i + 1 ; j <= n ; ++ j){
            if(a[i] >= a[j])continue;
            for(int k = j + 1 ; k <= n ; ++ k){
                if(a[j] >= a[k])continue;
                ll tmp = (ll)b[i] + (ll)b[j] + (ll)b[k];
                if(tmp < res)res = tmp;
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
