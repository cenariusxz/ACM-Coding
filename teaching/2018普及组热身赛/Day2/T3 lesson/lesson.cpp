//n two-point
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + ".out").c_str() ,"w",stdout);

    memset(vis,0,sizeof(vis));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int p1 = 1, p2 = 0;
    int sum = 0, ansl = 1, ansr = n;
    for(;p1 <= n ; ++ p1){
        while(p2 < n && sum < k){
            ++p2;
            vis[ a[p2] ]++;
            if(vis[ a[p2] ] == 1)sum++;
        }
        if(sum == k && p2 - p1 < ansr - ansl)ansl = p1, ansr = p2;
        vis[ a[p1] ]--;
        if(vis[ a[p1] ] == 0)sum--;
    }
    printf("%d %d\n",ansl,ansr);

    }

    return 0;
}
