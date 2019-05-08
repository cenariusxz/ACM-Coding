//nk suffix-min
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];
int suf[maxn],ans[maxn];
char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-nk.out").c_str() ,"w",stdout);

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ansl = 1, ansr = n;
    memset(ans,0,sizeof(ans));
    for(int p = 1 ; p <= k ; ++ p){
        suf[n+1] = n+1;
        for(int i = n ; i >= 1 ; -- i){
            if(a[i] == p)suf[i] = i;
            else suf[i] = suf[i+1];
            ans[i] = max(ans[i],suf[i]);
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        if(ans[i] == n+1)continue;
        if(ans[i] - i < ansr - ansl)ansl = i, ansr = ans[i];
    }
    printf("%d %d\n",ansl,ansr);

    }
    return 0;
}
