#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    sort(a + 1 , a + n + 1);
    double ans = max(a[1], l - a[n]);
    for(int i = 2 ; i <= n ; ++ i){
        ans = max(ans, (a[i] - a[i-1])/2.0);
    }
    printf("%.10lf\n",ans);
    return 0;
}
