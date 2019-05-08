#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n,m,k;
int a[1005];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    int ans = 0,b;
    for(int i = 1 ; i <= m ; ++ i){
        scanf("%d",&a[i]);
    }
    scanf("%d",&b);
    for(int i = 1 ; i <= m ; ++ i){
        int tmp = a[i]^b;
        int cnt = 0;
        while(tmp){
            if(tmp & 1)cnt++;
            tmp >>= 1;
        }
        if(cnt <= k)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
