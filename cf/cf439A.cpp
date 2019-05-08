#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int n,d;

int main(){
    scanf("%d%d",&n,&d);
    int sum = (n-1) * 10;
    for(int i = 1 ; i <= n ; ++ i){
        int a;
        scanf("%d",&a);
        sum += a;
    }
    if(sum > d)printf("-1\n");
    else printf("%d\n",(n - 1) * 2 + (d - sum)/5);
    return 0;
}
