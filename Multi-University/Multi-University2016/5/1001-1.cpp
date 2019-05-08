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
const int INF = (1 << 30) - 1;
const int mod = (int)1e9 + 7;
const int MAXN = 2010;

int K,W;
double dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

double Solve(int i,int j){
    // dp[a][b] --> [0 ~ a] , 剩余 b 次机会
    if(vis[i][j]) return dp[i][j];
    double res = INF;
    if(j == 1){
        res = (Solve(i - 1,j) * (i - 1.0 + 1.0) / (i + 1.0) + 
			Solve(0,j - 1) * (1.0 * 1) / (i + 1.0) + 1);
    }
    else{
		for(int k = 1; k <= i; ++k){
            res = min(res,Solve(i - k,j) * (i - k + 1.0) / (i + 1.0) + 
                Solve(k - 1,j - 1) * (1.0 * k) / (i + 1.0) + 1);
		}
    }
    vis[i][j] = true;
    return dp[i][j] = res;
}

int main(){
	memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    while(scanf("%d%d",&K,&W) != EOF){
		if(W>10)W=10;
        for(int i = 0; i <= W; ++i) vis[0][i] = 1;
        printf("%.6f\n",Solve(K,W));
    }
    return 0;
}

