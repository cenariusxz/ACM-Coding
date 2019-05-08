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
const int MAXN = 20010;

int T,n;
int t[MAXN],sum[MAXN];

ll Get(int p1,int p2){
	ll res = 1ll * sum[p1] * p1;
	res += 1ll * (sum[p2] - sum[p1]) * (p2 - p1);
	res += 1ll * (sum[n] - sum[p2]) * (n - p2);
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) scanf("%d",&t[i]);
		sort(t + 1,t + n + 1);
		for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + t[i];
		if(n <= 3){
			printf("%d\n",sum[n]);
			continue;
		}
		ll ans = -1;
		for(int i = 1; i <= n - 2; ++i){
			// 1~i in box1
			int l = i + 1,r = n;
			while(l < r - 2){
				int mid1 = getmid(l,r);
				int mid2 = getmid(mid1,r);
				if(mid1 == mid2) break;
				ll res1 = Get(i,mid1);
				ll res2 = Get(i,mid2);
				if(res1 < res2) r = mid2;
				else l = mid1;
			}
			for(int j = l; j <= r; ++j){
				if(ans == -1) ans = Get(i,j);
				else ans = min(ans,Get(i,j));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
