//n2 oioo -> binary answer
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];
char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};
int main(){
    for(int T = 1 ; T <= 6 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-n2-oioo.out").c_str() ,"w",stdout);

    memset(vis,0,sizeof(vis));
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ansl = 1, ansr = n;
    for(int len = 1 ; len < n ; ++len){
        if(ansr - ansl + 1 < len)break;
        memset(vis,0,sizeof(vis));
        int sum = 0;
        for(int i = 1 ; i <= len ; ++ i){
            vis[ a[i] ]++;
            if(vis[ a[i] ] == 1)sum ++;
        }
        if(sum == k){
            ansl = 1; ansr = len;
            break;
        }
        for(int l = 2 ; l + len - 1 <= n ; ++ l){
            vis[ a[l-1] ]--;
            if(vis[ a[l-1] ] == 0)sum --;
            vis[ a[l+len-1] ]++;
            if(vis[ a[l+len-1] ] == 1)sum ++;
            if(sum == k){
                ansl = l; ansr = l + len - 1;
                break;
            }
        }
    }
    printf("%d %d\n",ansl,ansr);

    }
    return 0;
}
