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
    int a,b;
    scanf("%d%d",&a,&b);
    int ans = a;
    while(a >= b){
        ans += a / b;
        a = a / b + a % b;
    }
    printf("%d\n",ans);
    return 0;
}
