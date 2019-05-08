//nlogn binary answer
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];
int ansl,ansr,n,k;

bool check(int len){
    memset(vis,0,sizeof(vis));
    int sum = 0;
    for(int i = 1 ; i <= len ; ++ i){
        vis[ a[i] ]++;
        if(vis[ a[i] ] == 1)sum ++;
    }
    if(sum == k){
        if(len < ansr - ansl + 1)ansl = 1; ansr = len;
        return 1;
    }
    for(int l = 2 ; l + len - 1 <= n ; ++ l){
        vis[ a[l-1] ]--;
        if(vis[ a[l-1] ] == 0)sum --;
        vis[ a[l+len-1] ]++;
        if(vis[ a[l+len-1] ] == 1)sum ++;
        if(sum == k){
            if(len < ansr - ansl + 1)ansl = l; ansr = l + len - 1;
            return 1;
        }
    }
    return 0;
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-nlogn.out").c_str() ,"w",stdout);

    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    ansl = 1, ansr = n;
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid))r = mid - 1;
        else l = mid + 1;
    }
    printf("%d %d\n",ansl,ansr);

    }
    return 0;
}
