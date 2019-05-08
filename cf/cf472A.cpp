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
    int n;
    scanf("%d",&n);
    int p1 = 4,p2;
    while(1){
        p2 = n - p1;
        if( p2 % 3 == 0 )break;
        p1+=2;
    }
    printf("%d %d\n",p1,p2);
    return 0;
}
