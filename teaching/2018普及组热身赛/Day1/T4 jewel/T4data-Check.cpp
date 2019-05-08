#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll dp[maxn][20];
int a[20][20];

inline ll max(ll a, ll b){return a > b ? a : b;}

int main(){
    freopen("T4-10.in","r",stdin);
    freopen("T4-10-c.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n < 1 || n > 16)printf("NO\n");
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < n ; ++ j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0 ; i < n ; ++ i){
        if(a[i][i] != 0)printf("NO\n");
        for(int j = 0 ; j < n ; ++ j){
            if(a[i][j] != a[j][i] || a[i][j] < 0 || a[i][j] > 1000000000)printf("NO\n");
        }
    }
    printf("AC\n");
    return 0;
}
