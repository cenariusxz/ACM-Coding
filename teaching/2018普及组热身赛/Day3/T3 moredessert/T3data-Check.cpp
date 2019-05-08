#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

ll a[maxn],b[maxn],c[maxn],s[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T3-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T3-") + ID[T] + "-c.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    if(n < 1 || n > 100)printf("NO\n");
/*    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&b[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&c[i]);
    for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&s[i]);
    ll sum = 0 ;
    for(int i = 1 ; i <= n ; ++ i)sum += s[i];
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 0 ; j <= sum ; ++ j)if(a[i] * j * j + b[i] * j + c[i] <= 0)printf("NONONO\n");
        if(T <= 3 && ( a[i] != 0 || b[i] != 0  || c[i] < 1 || c[i] > 1000 ))printf("NO\n");
        if(T > 3 && T <= 6 && ( a[i]!= 0 || b[i] < 1 || b[i] > 1000 || c[i] < 1 || c[i] > 1000 ))printf("NO\n");
        if(T > 6 && ( a[i] < 0 || a[i] > 1000 || c[i] < 0 || c[i] > 1000 || b[i] < -1000 || b[i] > 1000))printf("NO\n");
    }*/
    int sum = 0;
    while(scanf("%lld",&a[1])!=EOF)sum++;
    if(sum != 4*n)printf("WA\n");
    printf("AC2\n");

    }
    return 0;
}
