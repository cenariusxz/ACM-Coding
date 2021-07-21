#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int n, a[maxn];
double p[maxn], dp[4][maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			if(i == j)continue;
			p[a[i] - a[j] + 5000] += 1.0 / (n*(n-1));
		}
	}
	// printf("%lf %lf %lf %lf %lf %lf\n", p[5008], p[4992], p[5009], p[4991], p[5001], p[4999]);
	// printf("%lf\n", p[5008]+p[4992]+p[5009]+p[4991]+p[5001]+p[4999]);
	
	dp[0][15000] = 1;
	for(int t = 1 ; t <= 3 ; ++ t){
		for(int pre = 15000 - (t-1) * 5000 ; pre <= 15000 + (t-1) * 5000 ; ++ pre){
			if(fabs(dp[t-1][pre]) < eps)continue;
			if(t < 3){
				for(int delta = 5001 ; delta <= 10000 ; ++ delta){
					if(pre + delta - 5000 > 30000 || fabs(p[delta]) < eps)continue;
					dp[t][pre + delta - 5000] += p[delta] * dp[t-1][pre];
				}
			}
			else{
				for(int delta = 0 ; delta <= 4999 ; ++ delta){
					if(pre + delta - 5000 < 0 || fabs(p[delta]) < eps)continue;
					dp[t][pre + delta - 5000] += p[delta] * dp[t-1][pre];
				}
			}
		}
	}
	double ans = 0;
	for(int i = 0 ; i < 15000 ; ++ i)ans += dp[3][i];
	printf("%.12lf\n", ans * 8);
	return 0;
}

