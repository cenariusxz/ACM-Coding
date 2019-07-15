#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2000 + 5;
const int maxm = 1e6 + 6;

int n,m,k;
int a[maxn][maxn];
int sum[maxn][maxn];
int lu[maxn][maxn],ru[maxn][maxn],ld[maxn][maxn],rd[maxn][maxn];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++ i){		//二维前缀和 
		for(int j = 1 ; j <= m ; ++ j){
			a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	
	for(int i = k ; i <= n ; ++ i){		// 以（i，j）为右下角的k*k和 
		for(int j = k ; j <= m ; ++ j){
			sum[i][j] = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];	
		}
	}
	
	for(int i = k ; i <= n ; ++ i){
		for(int j = k ; j <= m ; ++ j){
			lu[i][j] = max(sum[i][j], max(lu[i-1][j], lu[i][j-1]));
		}
	}
	for(int i = k ; i <= n ; ++ i){
		for(int j = m-k+1 ;	j >= 1 ; -- j){
			ru[i][j] = max(sum[i][j+k-1], max(ru[i-1][j], ru[i][j+1]));
		}
	}
	for(int i = n-k+1 ; i >= 1 ; -- i){
		for(int j = k ; j <= m ; ++ j){
			ld[i][j] = max(sum[i+k-1][j], max(ld[i+1][j], ld[i][j-1]));
		}
	}
	for(int i = n-k+1 ; i >= 1 ; -- i){
		for(int j = m-k+1 ; j >= 1 ; -- j){
			rd[i][j] = max(sum[i+k-1][j+k-1], max(rd[i+1][j], rd[i][j+1]));
		}
	}
	
	int ans = 0;
	for(int i = k ; i <= n ; ++ i){		// 两竖，中间方形的右下角为（i，j） 
		for(int j = k+k ; j <= m-k ; ++ j){
			ans = max(ans, sum[i][j] + lu[n][j-k] + ru[n][j+1]);
		}
	}
	for(int i = k+k ; i <= n-k ; ++ i){	// 两横，中间方形的右下角为（i，j）
		for(int j = k ; j <= m ; ++ j){
			ans = max(ans, sum[i][j] + lu[i-k][m] + ld[i+1][m]);
		}
	}
	for(int i = k ; i <= n-k ; ++ i){	//2\3象限分开 
		for(int j = k ; j <= m-k ; ++ j){
			ans = max(ans, lu[i][j] + ld[i+1][j] + rd[1][j+1]);
		}
	}
	for(int i = k ; i <= n-k ; ++ i){	//1\4象限分开 
		for(int j = k ; j <= m-k ; ++ j){
			ans = max(ans, lu[n][j] + ru[i][j+1] + rd[i+1][j+1]);
		}
	}
	for(int i = k ; i <= n-k ; ++ i){	//1\2象限分开 
		for(int j = k ; j <= m-k ; ++ j){
			ans = max(ans, lu[i][j] + ru[i][j+1] + rd[i+1][1]);
		}
	}
	for(int i = k ; i <= n-k ; ++ i){	//3\4象限分开 
		for(int j = k ; j <= m-k ; ++ j){
			ans = max(ans, lu[i][m] + ld[i+1][j] + rd[i+1][j+1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

