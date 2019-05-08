#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn],h[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d%d",&h[i],&a[i]);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            if(i == j)continue;
            if(a[i] == h[j])ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
