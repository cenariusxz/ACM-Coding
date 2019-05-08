#include <bits/stdc++.h>
using namespace std;

int vis[30],a[30],n,r;

void dfs(int s){    //已考虑完前s个数了
    if(s == r){
        for(int i = 1 ; i <= r ; ++ i)printf("%3d",a[i]);
        printf("\n");
        return;
    }
    for(int i = a[s]+1 ; i <= n ; ++ i){
        if(vis[i])continue;
        vis[i] = 1;
        a[s+1] = i;
        dfs(s+1);
        vis[i] = 0;
    }
}

int main(){
    scanf("%d%d",&n,&r);
    memset(vis,0,sizeof(vis));
    dfs(0);
    return 0;
}
