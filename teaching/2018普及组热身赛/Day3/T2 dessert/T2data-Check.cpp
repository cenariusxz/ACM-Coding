#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

ll a[maxn],s[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T2-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T2-") + ID[T] + "-c.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    if(T <= 4 && (n<1 || n > 100))printf("NO\n");
    if(T > 4 && T <= 7 && (n<1 || n > 1000))printf("NO\n");
    if(T > 7  && (n<1 || n > 100000))printf("NO\n");
    int nn = 0;
    while(scanf("%lld",&a[1])!=EOF){
        nn++;
        if(T <= 4 && (a[1] < 1 || a[1] > 1000))printf("NO\n");
        if(T > 4 && (a[1] < 1 || a[1] > 100000) )printf("NO\n");
    }
    if(nn != 2*n)printf("WA\n");
    printf("AC\n");

    }
    return 0;
}
