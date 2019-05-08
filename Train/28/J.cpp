#include <stdio.h>

typedef long long ll;

int N,M,T;
int pnum[100];
int cnt,ans;

const int mod = 100000007;

int main(){
	int tt = 0;
	while(scanf("%d%d%d",&N,&M,&T) != EOF){
		if(N == 0 && M == 0 && T == 0) break;
		cnt = 0;
		for(int i = 2; i * i <= N; ++i) if(N % i == 0){
			++cnt;
			pnum[cnt] = 0;
			while(N % i == 0){
				pnum[cnt]++;
				N /= i;
			}
		}
		if(N > 1) pnum[++cnt] = 1;
		ans = 1;
		int res = 1;
		for(int i = 1; i <= cnt; ++i){
			ll num = 1ll * pnum[i] * M;
			ll v1 = num / T;
			ll v2 = num / (T + 1);
			ans = 1ll * ans * (v1 + 1) % mod;
			res = 1ll * res * (v2 + 1) % mod;
		}
		ans = ((ans - res) % mod + mod) % mod;
		printf("Case %d: %d\n",++tt,ans);
	}
	return 0;
}
