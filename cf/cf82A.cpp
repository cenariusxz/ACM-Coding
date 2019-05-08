#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn],t[maxn],p[maxn];
int vis[maxn];

int main(){
    scanf("%s%s%s",s,t,p);
    for(int i = 0 ; s[i] ; ++ i)vis[s[i]]++;
    for(int i = 0 ; t[i] ; ++ i)vis[t[i]]++;
    for(int i = 0 ; p[i] ; ++ i)vis[p[i]]--;
    for(int i = 'A' ; i <= 'Z' ; ++ i){
        if(vis[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
