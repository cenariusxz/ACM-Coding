#include <cstdio>
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
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int Euler(int v){
	int res = v;
	int k = sqrt(1.0 * v);
	for(int i = 2; i <= k; ++i) if(v % i == 0){
		while(v % i == 0) v /= i;
		res = res / i * (i - 1);
	}
	if(v > 1) res = res / v * (v - 1);
	return res;
}

int T,n,m;
int A[10010];
set<int> st;
set<int>::iterator it;

int Gcd(int a,int b){
	return b == 0 ? a : Gcd(b,a % b);
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		st.clear();
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; ++i){
			scanf("%d",&A[i]);
			A[i] = Gcd(A[i],m);
		}
		ll ans = 0;
		sort(A + 1,A + n + 1);
		int sz = unique(A + 1,A + n + 1) - A - 1;
		for(int i = 1; i <= sz; ++i){
			for(int g = A[i]; g <= m; g += A[i]) if(m % g == 0){
				st.insert(g);
			}
		}
		for(it = st.begin(); it != st.end(); ++it){
			int g = (*it);
			ans += 1ll * Euler(m / g) * (m / g) / 2 * g;
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}
