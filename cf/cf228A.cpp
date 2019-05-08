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
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ans = 0;
    if(a == b || a == c || a == d)ans++;
    if(b == c || b == d)ans++;
    if(c == d)ans++;
    printf("%d\n",ans);
    return 0;
}
