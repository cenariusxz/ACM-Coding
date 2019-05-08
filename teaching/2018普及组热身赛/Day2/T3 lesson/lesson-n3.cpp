//n3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 2 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-n3.out").c_str() ,"w",stdout);

    memset(vis,0,sizeof(vis));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ansl = 1, ansr = n;
    for(int len = 1 ; len <= n ; ++ len){
        if(ansr - ansl + 1 <= len)break;
        for(int l = 1 ; l <= n ; ++ l){
            int r = l + len - 1, sum = 0;
            if(r > n)continue;
            memset(vis,0,sizeof(vis));
            for(int i = l ; i <= r ; ++ i){
                vis[ a[i] ]++;
                if(vis[ a[i] ] == 1)sum ++;
            }
            if(sum == k){
                ansl = l; ansr = r;
                break;
            }
        }
    }
    printf("%d %d\n",ansl,ansr);
    }
    return 0;
}
