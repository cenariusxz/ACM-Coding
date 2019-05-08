#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int M[maxn][maxn];
int n,m;
int num = 0;

void dfs(int s,int dep){
    if(dep > num)num = dep;
    for(int i = 1 ; i <= n ; ++ i){
        if(M[s][i])dfs(i,dep+1);
    }
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 6 ; T <= 6 ; ++ T){
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-dfs.out").c_str() ,"w",stdout);

    scanf("%d%d",&n,&m);
    memset(M,0,sizeof(M));
    for(int i = 1 ; i <= m ; ++ i){
        int a,b;
        scanf("%d%d",&a,&b);
        M[a][b] = 1;
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        num = 0;
        dfs(i,1);
        ans = max(ans,num);
    }
    printf("%d\n",ans);

    }
    return 0;
}
