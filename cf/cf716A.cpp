#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n,m;
int a;

int main(){
    scanf("%d%d",&n,&m);
    int ans = 0,pre = -INF;
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d",&a);
        if(a - pre <= m)ans++;
        else ans = 1;
        pre = a;
    }
    printf("%d\n",ans);
    return 0;
}
