//n2k
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];
char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};
int main(){
    for(int T = 1 ; T <= 6 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-n2k.out").c_str() ,"w",stdout);

    memset(vis,0,sizeof(vis));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ansl = 1, ansr = n;
    for(int l = 1 ; l <= n ; ++l){
        memset(vis,0,sizeof(vis));
        for(int r = l ; r <= n ; ++ r){
            vis[ a[r] ] ++;
            int sum = 0;
            for(int i = 1 ; i <= k ; ++ i)if(vis[i])sum ++;
            if(sum == k){
                if(r - l < ansr - ansl)ansl = l, ansr = r;
                break;
            }
        }
    }
    printf("%d %d\n",ansl,ansr);
    }
    return 0;
}
