#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const ll INF = 1LL << 60;
const int MAXN = 310;

ll L,R;
int s[100],len;
ll dp[100][2][2][2][3][2];

ll Dfs(int p,int f,int odd,int even,int pre,int st){
    if(p > len){
        if(pre == 2) return 1;
        if(pre == 0 && even == 1) return 1;
        if(pre == 1 && odd == 0) return 1;
        return 0;
    }
    if(dp[p][f][odd][even][pre][st] != -1) return dp[p][f][odd][even][pre][st];
    ll res = 0;
    int top = (f == 1) ? 9 : s[p];
    for(int i = 0; i <= top; ++i){
        int now = i & 1;
        if(st == 0 && i == 0){
            res += Dfs(p + 1,f | (i < s[p]),odd,even,pre,st);
            continue;
        }
        if(pre == 2){
            res += Dfs(p + 1,f | (i < s[p]),(odd + (now == 1)) % 2,(even + (now == 0)) % 2,now,st | (i > 0));
        }
        else if(now == pre){
            if(now == 0) res += Dfs(p + 1,f | (i < s[p]),0,(even + 1) % 2,now,st | (i > 0));
            else         res += Dfs(p + 1,f | (i < s[p]),(odd + 1) % 2,0,now,st | (i > 0));
        }
        else if(pre == 0 && even == 1){
            res += Dfs(p + 1,f | (i < s[p]),1,0,now,st | (i > 0));
        }
        else if(pre == 1 && odd == 0){
            res += Dfs(p + 1,f | (i < s[p]),0,1,now,st | (i > 0));
        }
    }
    dp[p][f][odd][even][pre][st] = res;
    return res;
}

ll Solve(ll v){
    if(v == 0) return 1;
    memset(dp,-1,sizeof(dp));
    len = 0;
    while(v){
        s[++len] = v % 10;
        v /= 10;
    }
    for(int i = 1; i <= len / 2; ++i) swap(s[i],s[len + 1 - i]);
    return Dfs(1,0,0,0,2,0);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%lld%lld",&L,&R);
        printf("Case #%d: %lld\n",tt,Solve(R) - Solve(L - 1));
    }
    return 0;
}
