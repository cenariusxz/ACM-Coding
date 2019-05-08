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
    freopen( (string("T4-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T4-") + ID[T] + "-c.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    if( T <= 4 && (n < 2 || n > 100) )printf("NO\n");
    if( T > 4 && T <= 7 && (n < 2 || n > 2000) )printf("NO\n");
    if( T > 7 && (n < 2 || n > 100000) )printf("NO\n");

    int sum = 0;
    while(scanf("%lld",&a[1])!=EOF){
        sum++;
        if(a[1] < 1)printf("NO\n");
        if(T <= 4 && a[1] > 10000)printf("NO\n");
        if(T > 4 && T <= 7 && a[1] > 1000000)printf("NO\n");
        if(T > 7 && a[1] > 1000000000)printf("NO\n");
    }
    if(sum != n)printf("WA\n");
    printf("AC2\n");

    }
    return 0;
}
