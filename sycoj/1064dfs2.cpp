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
int vis[50];
int num[50];

bool check(int x){
    if(x < 2)return 0;
    for(int i = 2 ; i * i <= x ; ++ i){
        if( x % i == 0 )return 0;
    }
    return 1;
}

void dfs(int t,int sum){
    if(t == n){
    	int cnt = 0;
    	for(int i = 1 ; i <= n ; ++ i)cnt += vis[i];
		if(cnt != k)return; 
        if(check(sum))ans++;
        return;
    }
    vis[t+1] = 0;
    dfs(t+1, sum);
    vis[t+1] = 1;
    dfs(t+1, sum + num[t+1]);
    vis[t+1] = 0;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
    dfs(0,0);
    printf("%d\n",ans);
    return 0;
}
