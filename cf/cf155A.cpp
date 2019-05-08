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
    int n,ma,mi;
    scanf("%d%d",&n,&ma);
    mi = ma;
    int ans = 0;
    for(int i = 1 ; i < n ; ++ i){
        int a;
        scanf("%d",&a);
        if(a > ma)ma = a,ans++;
        if(a < mi)mi = a,ans++;
    }
    printf("%d\n",ans);
    return 0;
}
