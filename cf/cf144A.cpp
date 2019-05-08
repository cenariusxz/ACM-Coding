#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int pos1 = -1 , pos2 = -1;
    for(int i = 1 ; i <= n ; ++ i){
        if(pos1 == -1 || a[i] > a[pos1])pos1 = i;
    }
    for(int i = n ; i >= 1 ; -- i){
        if(pos2 == -1 || a[i] < a[pos2])pos2 = i;
    }
    int ans = pos1 - 1 + n - pos2;
    if(ans >= n)ans--;
    printf("%d\n",ans);
    return 0;
}
