#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;

int vis[maxn][maxn];
int x[maxn],y[maxn];

int main(){
    freopen("T2-10.in","r",stdin);
    freopen("T2-10-c.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if( n < 1 || n > 1000 || m < 1 || m > 1000 || k < 1 || k > 100)printf("NO\n");
    for(int i = 1 ; i <= k ; ++ i){
        scanf("%d%d",&x[i],&y[i]);
        if( x[i] < 1 || x[i] > n || y[i] < 1 || y[i] > m || vis[x[i]][y[i]])printf("NO\n");
        vis[x[i]][y[i]] = 1;
    }
    return 0;
}
