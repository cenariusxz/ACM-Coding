#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int dp[maxn],id[maxn];
int M[maxn][maxn];
int n,m;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
        freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
        freopen( (string("T4-") + ID[T] + "-c.out").c_str() ,"w",stdout);

        scanf("%d%d",&n,&m);
        if(m < 1 || m > n*(n-1)/2)printf("NO1\n");
        if(T <= 2 && (n < 1 || n > 10))printf("NO\2n");
        if(T > 2 && T <=5 && (n < 1 || n > 100))printf("NO2\n");
        if(T > 5 && (n < 1 || n > 1000))printf("NO2\n");


        memset(M,0,sizeof(M));
        for(int i = 1 ; i <= m ; ++ i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a < 1 || a > n || b < 1 || b > n)printf("NO3\n");
            if(M[a][b])printf("NO4 %d %d %d\n",a,b,M[a][b]);
            M[a][b] = 1;
        }
/*        int sum = 0,a,b;
        while(scanf("%d%d",&a,&b)!=EOF)sum ++;
        if(sum!=m)printf("WA\n");*/
        printf("AC\n");
    }
    return 0;
}
