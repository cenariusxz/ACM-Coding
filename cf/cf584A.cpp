#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 1 && m == 10)printf("-1\n");
    else{
        n--;
        if(m == 10)n--;
        printf("%d",m);
        for(int i = 1 ; i <= n ; ++ i)printf("0");
        printf("\n");
    }
    return 0;
}
