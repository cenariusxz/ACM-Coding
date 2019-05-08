#include <stdio.h>
#include <math.h>

typedef long long ll;
const int mod = 1e9 + 7;;
const int MAXN = 5010;
int n,l,r;
int dp[5010][5010];
int C[5010][5010];
int sum[5010];
int fac[MAXN + 10],afac[MAXN + 10];

int Q_pow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

void Pre(){
	fac[0] = afac[0] = 1;
	for(int i = 1; i <= MAXN; ++i) fac[i] = fac[i - 1] * (ll)i % mod;
	afac[MAXN] = Q_pow(fac[MAXN],mod - 2);
	for(int i = MAXN; i >= 1; --i) afac[i - 1] = afac[i] * i % mod;
	dp[1][1] = 1;
	for(int j = 1; j <= 5; ++j){
		if(j > 1){
			for(int i = j; i <= 5; ++i){
				dp[j][i] = 1ll * fac[i - 1] * sum[i - 1] % mod;
				printf("dp[%d][%d] : %d\n",j,i,dp[j][i]);
			}
		}
		sum[j - 1] = 0;
		for(int i = j; i <= 5; ++i){
			sum[i - 1] = (sum[i] + 1ll * dp[j][i] * afac[i] % mod) % mod;
		}
	}
	printf("%d\n",dp[2][4]);
}

void PRE(){
	for(int i = 0; i <= 5000; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	dp[0][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i <= 5000; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i][j] = (dp[i - 1][j - 1] + 1ll * dp[i - 1][j] * (i - 1) % mod) % mod;
		}
	}
}

int main(){
	//Pre();
	PRE();
	while(scanf("%d%d%d",&n,&l,&r) != EOF && (n + l + r)){
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			ans = (ans + 1ll * dp[i - 1][l - 1] * dp[n - i][r - 1] % mod * C[n - 1][i - 1]) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
