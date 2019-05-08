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
    scanf("%d",&n);
    int ans = 0;
    int mi = INF;
    for(int i = 1 ; i <= n ; ++ i){
        int a,p;
        scanf("%d%d",&a,&p);
        if(p < mi)mi = p;
        ans += mi * a;
    }
    printf("%d\n",ans);
    return 0;
}
