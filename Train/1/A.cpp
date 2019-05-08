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
const int MAXN = 40;

ll G[MAXN][MAXN];

ll Det(int n){
	ll A[MAXN][MAXN];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			A[i][j] = G[i][j];
		}
	}
	ll res = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			while(A[j][i]){
				ll t = A[i][i] / A[j][i];
				for(int k = i; k <= n; ++k){
					A[i][k] = (A[i][k] - A[j][k] * t);
				}
				for(int k = i; k <= n; ++k){
					swap(A[i][k],A[j][k]);
				}
				res = -res;
			}
		}
		if(!A[i][i]) return 0;
		res = res * A[i][i];
	}
	return res;
}

int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(G,0,sizeof(G));
		int id[MAXN][MAXN];
		int c = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				id[i][j] = ++c;
			}
		}
		int dir[4][2] = {{-1,0},{-1,-1},{0,-1},{1,-1}};
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				for(int k = 0; k < 4; ++k){
					int ti = i + dir[k][0];
					int tj = j + dir[k][1];
					if(ti < 1 || ti > n || tj < 1 || tj > n)
						continue;
					G[id[i][j]][id[i][j]]++;
					G[id[ti][tj]][id[ti][tj]]++;
					G[id[i][j]][id[ti][tj]] = -1;
					G[id[ti][tj]][id[i][j]] = -1;
				}
			}
		}
		/*for(int i = 1; i <= n * n; ++i){
			for(int j = 1; j <= n * n; ++j){
				printf("%d ",G[i][j]);
			}
			puts("");
		}*/
		ll ans = Det(n * n - 1);
		printf("%lld\n",ans);
	}
	return 0;
}
