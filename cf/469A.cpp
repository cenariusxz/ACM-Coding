#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int vis[maxn];

int main(){
    int n,p,ans = 0;
    scanf("%d",&n);
    scanf("%d",&p);
    for(int i = 1 ; i <= p ; ++ i){
        int a;
        scanf("%d",&a);
        if(!vis[a])vis[a] = 1, ans++;
    }
    scanf("%d",&p);
    for(int i = 1 ; i <= p ; ++ i){
        int a;
        scanf("%d",&a);
        if(!vis[a])vis[a] = 1, ans++;
    }
    if(ans == n)printf("I become the guy.\n");
    else printf("Oh, my keyboard!\n");
    return 0;
}
