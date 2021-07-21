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

int a, b, c;	// a(i), b(j), c(k) - i kill j, j kill k, k kill i
double dp[105][105][105];

int main(){
	scanf("%d%d%d", &a, &b, &c);
	dp[a][b][c] = 1.0;
	for(int i = a ; i >= 0 ; -- i){
		for(int j = b ; j >= 0 ; -- j){
			for(int k = c ; k >= 0 ; -- k){
				double sum = i * j + i * k + j * k;
				if(i * j)dp[i][j-1][k] += (i*j) / sum * dp[i][j][k];
				if(i * k)dp[i-1][j][k] += (i*k) / sum * dp[i][j][k];
				if(j * k)dp[i][j][k-1] += (j*k) / sum * dp[i][j][k];
			}
		}
	}
	double ansa = 0, ansb = 0, ansc = 0;
	for(int i = 1 ; i <= a ; ++ i)ansa +=  dp[i][0][0];
	for(int i = 1 ; i <= b ; ++ i)ansb +=  dp[0][i][0];
	for(int i = 1 ; i <= c ; ++ i)ansc +=  dp[0][0][i];
	printf("%.12lf %.12lf %.12lf\n", ansa, ansb, ansc);
	return 0;
}

