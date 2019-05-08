#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e5 + 5;
const int mod = 1e4 + 7;

vector<int>V[maxn];
int num[maxn],col[maxn];
int sum[2],cnt[2];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int col;
		scanf("%d",&col);
		V[col].PB(i);
	}
	int ans = 0;
	for(int col = 1 ; col <= m ; ++ col){
		int sz = V[col].size();
		sum[0]=sum[1]=cnt[0]=cnt[1] = 0;
		for(int i = sz-1 ; i >= 0 ; -- i){
			int x = V[col][i],nx = num[x]%mod;
			int now = x & 1;
			ans += x % mod * nx % mod * cnt[now] % mod;
			ans %= mod;
			ans += x % mod * sum[now] % mod;
			ans %= mod;
			sum[now] = (sum[now] + nx)%mod;
			cnt[now] = (cnt[now] + 1)%mod;
		}
		sum[0]=sum[1]=cnt[0]=cnt[1] = 0;
		for(int i = 0 ; i < sz ; ++ i){
			int x = V[col][i],nx = num[x]%mod;
			int now = x & 1;
			ans += x % mod * nx % mod * cnt[now] % mod;
			ans %= mod;
			ans += x % mod * sum[now] % mod;
			ans %= mod;
			sum[now] = (sum[now] + nx)%mod;
			cnt[now] = (cnt[now] + 1)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
