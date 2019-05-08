#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

int a[105][maxn];

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){

    for(int T = 1 ; T <= 10 ; ++ T){
        freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
        freopen( (string("T2-") + ID[T] + "-c.out").c_str() ,"w",stdout);

        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);

        if(T <= 3 && (n < 1 || n > 100 || k != 1 || m < 1 || m > 10))printf("NO\n");
        if(T > 3 && T <=6 && (n < 1 || n > 1000 || k < 1 || k > 10 || m < 1 || m > 10))printf("NO\n");
        if(T > 6 && (n < 1 || n > 10000 || k <1 || k > n || m < 1 || m > 10))printf("NO\n");
/*
        for(int i = 1 ; i <= n ; ++ i){
            for(int j = 1 ; j <= m ; ++ j){
                scanf("%d",&a[j][i]);
                if(T <= 3 && (a[j][i] < 1 || a[j][i] > 100))printf("NO\n");
                if(T > 3 && (a[j][i] < 1 || a[j][i] > 1000000000))printf("NO\n");
            }
        }*/
        int sum = 0;
        while(scanf("%d",&a[1][1])!=EOF)sum++;
        if(sum != n*m)printf("WA\n");
        printf("AC2\n");
    }

    return 0;
}
