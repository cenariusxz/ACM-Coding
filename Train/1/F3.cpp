#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
const int MAXN = 100010;
const int MAX_LOG = 18;
const ll mod = 10007;

int T,n,W;
ll dp[110][110][1010],id[1010];
pii P[110];
ll C[110][110];
ll prelen[110],prenum[110];
ll fac[110],afac[110],preafac[110];

ll Q_pow(ll x,ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

ll A(ll n,ll m){
	return 1ll * fac[n] * afac[n - m] % mod;
}

void Magic(ll &a,ll b){
	a += b;
	if(a >= mod) a -= mod;
}

int main(){
	//freopen("data.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	fac[0] = afac[0] = 1;
	for(int i = 1; i <= 100; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	afac[100] = Q_pow(fac[100],mod - 2);
	for(int i = 99; i >= 1; --i) afac[i] = 1ll * afac[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= 100; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&n,&W);
		memset(id,0,sizeof(id));
		memset(dp,0,sizeof(dp));
		memset(preafac,0,sizeof(preafac));
		memset(prelen,0,sizeof(prelen));
		memset(prenum,0,sizeof(prenum));
		for(int i = 1; i <= n; ++i){
			P[i].first = P[i].second = 0;
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			int a;
			scanf("%d",&a);
			if(id[a] == 0){
				id[a] = ++cnt;
				P[cnt].first = a;
			}
			P[id[a]].second++;
		}
		sort(P + 1,P + cnt + 1);
		preafac[0] = 1;
		prelen[0] = prenum[0] = 0;
		for(int i = 1; i <= cnt; ++i){
			prelen[i] = (prelen[i - 1] + P[i].first * P[i].second) % mod;
			prenum[i] = (prenum[i - 1] + P[i].second) % mod;
			preafac[i] = 1ll * preafac[i - 1] * afac[P[i].second] % mod;
		}
		ll ans = 0;
		dp[cnt + 1][0][0] = 1;
		for(int o = cnt; o >= 1; --o){
			for(int i = 0; i <= n; ++i)
				for(int j = 0; j <= W; ++j)
					dp[o][i][j] = dp[o + 1][i][j];
			//枚举最小长度是谁
			for(int k = 0; k <= P[o].second; ++k){
				if(k){
					for(int i = n; i >= k; --i){
						for(int j = W; j >= 1; --j){
							if(j - k * P[o].first >= 0){
								Magic(dp[o][i][j],1ll * C[i][k] * 
										dp[o + 1][i - k][j - k * P[o].first] % mod);
							}
						}
					}
				}
				if(k == P[o].second - 1){
					//刚好没取完，最小长度是 P[o].first
					//j 的范围：[W - P[o].first + 1,W]
					for(int i = 0; i <= n - prenum[o - 1]; ++i){
						for(int j = 0; j <= W; ++j) if(dp[o][i][j]){
							//现在是 i + prenum[o - 1] 个
							if(j + prelen[o - 1] <= W - P[o].first || j + prelen[o - 1] > W) continue;
							ll cof = 1ll * A(i + prenum[o - 1],prenum[o - 1]) * preafac[o - 1] % mod;
							if(i == 0 && j == 0 && o == 1) continue;
							Magic(ans,cof * dp[o][i][j] % mod);
						}
					}
				}
			}
		}
		if(prelen[cnt] <= W){
			Magic(ans,fac[n] * preafac[cnt] % mod);
		}
		printf("Case %d: %lld\n",tt,ans);
	}
	return 0;
}
