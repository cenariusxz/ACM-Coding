#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n;
double a[100][100], p[10][100], dp[10][100]; 

int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < (1<<n) ; ++ i){
		for(int j = 0 ; j < (1<<n) ; ++ j){
			scanf("%lf", &a[i][j]);
			a[i][j] /= 100.0;	
		}
		p[0][i] = 1;
	}
	for(int k = 0 ; k < n ; ++ k){
		int rd = k+1;
		for(int i = 0 ; i < (1<<n) ; ++ i){
			int st = ((i>>k)<<k)^(1<<k);
			double e1 = dp[rd-1][i], e2 = 0.0, e3 = 0.0;
			for(int q = 0 ; q < (1<<k) ; ++ q){
				int j = st + q;
				int sc = 1 << k;
				p[rd][i] += p[rd-1][i] * p[rd-1][j] * a[i][j];
				e2 = max(e2, dp[rd-1][j]);
				e3 += p[rd-1][i] * p[rd-1][j] * a[i][j] * sc;
			}
			dp[rd][i] = e1 + e2 + e3;
		}
	}
	double ans = 0;
	for(int i = 0 ; i < (1<<n) ; ++ i)ans = max(ans, dp[n][i]);
	printf("%.12lf\n", ans);
	return 0;
}

