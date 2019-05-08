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
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%d",&a[i]);
        a[i] %= 2;
    }
    for(int i = 1 ; i <= n - 2 ; ++ i){
        if(a[i] != a[i+1] && a[i] != a[i+2]){
            printf("%d\n",i);
            return 0;
        }
        if(a[i+1] != a[i] && a[i+1] != a[i+2]){
            printf("%d\n",i+1);
            return 0;
        }
        if(a[i+2] != a[i] && a[i+1] != a[i+2]){
            printf("%d\n",i+2);
            return 0;
        }
    }
    return 0;
}
