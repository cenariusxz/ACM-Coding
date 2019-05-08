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
    int n,m = 0;
    scanf("%d",&n);
    int ans = 0;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a > 0) m += a;
        else if(a == -1 && m)m --;
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}
