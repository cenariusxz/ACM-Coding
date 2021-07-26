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

double dp[2005][2005];
int vis[2][2005], n, m, a, b;

int main(){
	scanf("%d%d", &n, &m);
	while(m --){
		scanf("%d%d", &a, &b);
		vis[0][a] = 1;
		vis[1][b] = 1;
	}
	a = 0, b = 0;
	for(int i = 1 ; i <= n ; ++ i)a += 1 - vis[0][i];
	for(int i = 1 ; i <= n ; ++ i)b += 1 - vis[1][i];
	for(int i = 0 ; i <= a ; ++ i){
		for(int j = 0 ; j <= b ; ++ j){
			if(!i && !j)continue;
			if(j)dp[i][j] += (n-i) * j * dp[i][j-1];
			if(i)dp[i][j] += i * (n-j) * dp[i-1][j];
			if(i && j)dp[i][j] += i * j * dp[i-1][j-1];
			dp[i][j] += n * n;
			dp[i][j] /= (i*n + j*n - i*j);
		}
	}
	printf("%.12lf\n", dp[a][b]);
	return 0;
}

