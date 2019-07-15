#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,k,ans = 0;
int a[50];
int num[50];

bool check(int x){
    if(x < 2)return 0;
    for(int i = 2 ; i * i <= x ; ++ i){
        if( x % i == 0 )return 0;
    }
    return 1;
}

void dfs(int t,int sum){
    if(t == k){
        if(check(sum))ans++;
        return;
    }
    for(int i = a[t] + 1 ; i <= n ; ++ i){
        a[t+1] = i;
        dfs(t+1,sum + num[i]);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
