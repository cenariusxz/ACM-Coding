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

int w, b;
double dp[1005][1005];

int main(){
	scanf("%d%d", &w, &b);
	dp[w][b] = 1;
	double ans = 0;
	for(int i = w ; i >= 1 ; -- i){
		for(int j = b ; j >= 0 ; -- j){
			if((w + b - i - j) % 3 == 0){
				ans += (double)i / (i+j) * dp[i][j];
				if(j)dp[i][j-1] += (double)j / (i+j) * dp[i][j];
			}
			else if((w + b - i - j) % 3 == 1){
				if(j)dp[i-1][j-1] += (double)j * i / (i+j) / (i+j-1) * dp[i][j];
				if(j > 1)dp[i][j-2] += (double)j * (j-1) / (i+j) / (i+j-1) * dp[i][j];
			}
		}
	}
	printf("%.12lf\n", ans);
	return 0;
}

