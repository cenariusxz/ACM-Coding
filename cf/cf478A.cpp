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
    int ans = 0;
    for(int i = 1 ; i <= 5 ; ++ i){
        int a;
        scanf("%d",&a);
        ans+=a;
    }
    if(ans % 5 || ans == 0)printf("-1\n");
    else printf("%d\n",ans/5);
    return 0;
}
