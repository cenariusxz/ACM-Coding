#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n;

int main(){
    int ans = 0;
    int a1,a2,a3;
    scanf("%d%d%d",&a1,&a2,&a3);
    ans += (a1+a2+a3)/5 + ( (a1+a2+a3)%5 != 0 );
    scanf("%d%d%d",&a1,&a2,&a3);
    ans += (a1+a2+a3)/10 + ( (a1+a2+a3)%10 != 0 );
    scanf("%d",&n);
    if(ans <= n)printf("YES\n");
    else printf("NO\n");
    return 0;
}
