#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans = (((n+1)/2-1)/m+1)*m;
    if(ans >= (n+1)/2 && ans <= n)printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
