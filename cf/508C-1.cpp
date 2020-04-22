#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int m, t, r;
int w[305], cnt[1005]; 

int solve(){
	if(t < r)return -1;
	int ans = 0;
	for(int i = 1 ; i <= m ; ++ i)w[i] += 300;
	for(int i = 1 ; i <= m ; ++ i){
		int need = r - cnt[w[i]];
		for(int ti = w[i] - need ; ti <= w[i] - 1 ; ++ ti){
			for(int j = ti + 1 ; j <= ti + t ; ++ j)cnt[j] ++;
			ans ++;
		}
	}
	return ans;
}

int main(){
	scanf("%d%d%d", &m, &t, &r);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d", &w[i]);
	printf("%d\n", solve());
	return 0;
}


