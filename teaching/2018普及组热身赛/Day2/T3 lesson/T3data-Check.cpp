#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int a[maxn],vis[105];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){

    for(int T = 1 ; T <= 10 ; ++ T){
        freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
        freopen( (string("T3-") + ID[T] + "-c.out").c_str() ,"w",stdout);

        int n,k;
        scanf("%d%d",&n,&k);

        if(T <= 2 && (n < 1 || n > 100 || k < 1 || k > 10))printf("NO\n");
        if(T > 2 && T <=6 && (n < 1 || n > 2000 || k < 1 || k > 50))printf("NO\n");
        if(T > 6 && (n < 1 || n > 100000 || k <1 || k > 100))printf("NO\n");

        memset(vis,0,sizeof(vis));
        int sum = 0;
/*
        for(int i = 1 ; i <= n ; ++ i){
            scanf("%d",&a[i]);
            if(a[i] < 1 || a[i] > k)printf("NO\n");
            vis[ a[i] ] ++;
            if(vis[ a[i] ] == 1)sum ++;
        }
        if(sum != k)printf("NO\n");*/
        while(scanf("%d",&a[1])!=EOF)sum ++;
        if(sum != n)printf("WA\n");

        printf("AC2\n");
    }

    return 0;
}
