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

int n,K;
int G[510][510];
int Suf[510][510];
int S[510][510];
int dp[510][510];
int pre[510][510];

int main(){
	while(scanf("%d%d",&n,&K) != EOF){
		memset(G,0,sizeof(G));
		memset(S,0,sizeof(S));
		memset(pre,0,sizeof(pre));
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				scanf("%d",&G[i][j]);
			}
			Suf[i][n] = G[i][n];
			for(int j = n - 1; j >= i + 1; --j){
				Suf[i][j] = Suf[i][j + 1] + G[i][j];
			}
		}
		for(int j = 2; j <= n; ++j){
			S[j - 1][j] = Suf[j - 1][j];
			for(int i = j - 2; i >= 1; --i){
				S[i][j] = S[i + 1][j] + Suf[i][j];
			}
		}
		for(int i = 0; i <= 500; ++i){
			for(int j = 0; j <= 500; ++j){
				dp[i][j] = -INF;
			}
		}
		for(int i = 1; i <= n; ++i) dp[i][0] = 0;
		for(int i = 2; i <= n; ++i){
			int top = min(K,i - 1);
			for(int j = 1; j <= top; ++j){
				for(int k = 1; k < i; ++k){
					// dp[k][j - 1] --> dp[i][j]
					if(j - 1 > k - 1) continue;
					if(dp[k][j - 1] + S[k][i] > dp[i][j]){
						dp[i][j] = dp[k][j - 1] + S[k][i];
						pre[i][j] = k;
					}
				}
			}
		}
		int ans = 0;
		int kk = K,pos = n;
		for(int i = 1; i <= n; ++i){
			if(dp[i][K] > ans){
				ans = dp[i][K];
				pos = i;
			}
		}
		printf("%d\n",ans);
		vector<int> ansG;
		while(kk){
			ansG.PB(pos);
			pos = pre[pos][kk--];
		}
		sort(ansG.begin(),ansG.end());
		for(int i = 0; i < ansG.size(); ++i){
			printf("%d",ansG[i] - 1);
			if(i == ansG.size() - 1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}

