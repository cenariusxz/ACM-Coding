#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n,t;

int main(){
    scanf("%d%d",&n,&t);
    int p = 1;
    for(int i = 1 ; i < n ; ++ i){
        int b;
        scanf("%d",&b);
        if(p == i)p += b;
        if(p == t){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
