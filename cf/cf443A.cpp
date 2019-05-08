#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn];
int vis[maxn];

int main(){
    gets(s);
    int ans = 0;
    for(int i = 0 ; s[i] ; ++ i){
        if(s[i] >= 'a' && s[i] <= 'z' && !vis[s[i]])vis[s[i]] = 1,ans++;
    }
    printf("%d\n",ans);
    return 0;
}
