#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[maxn],b[maxn];
ll ans[maxn];

int main(){
    freopen("T3-10.in","r",stdin);
    freopen("T3-10-c.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&b[i]);
    if(n < 1 || n > 5000)printf("NO\n");
    for(int i = 1 ; i <= n ; ++ i){
        if(a[i] < 1 || a[i] > 1000000000)printf("NO\n");
        if(b[i] < 1 || b[i] > 1000000000)printf("NO\n");
    }
    printf("AC\n");
    return 0;
}
