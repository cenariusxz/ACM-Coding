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
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans = INF;
    int p = 0;
    while(1){
        int tmp = p * b;
        int num = n - m * p;
        if( num < 0 ) num = 0;
        tmp += num * a;
        if(tmp < ans)ans = tmp;
        if( m * p >= n)break;
        p++;
    }
    printf("%d\n",ans);
    return 0;
}
