#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans = 0;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a <= 5 - m)ans++;
    }
    printf("%d\n",ans/3);
    return 0;
}
