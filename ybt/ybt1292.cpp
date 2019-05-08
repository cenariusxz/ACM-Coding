#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,m,k;
int a[105],b[105];
int dp[1005][505]; 

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i <= k ; ++ i)scanf("%d%d",&a[i],&b[i]);
	for(int i = 1 ; i <= k ; ++ i){
		for(int j = n ; j >= a[i] ; -- j){
			for(int p = m-1 ; p >= b[i] ; -- p){
				dp[j][p] = max(dp[j][p], dp[j-a[i]][p-b[i]] + 1);
			}
		}
	}
	int ans1=0, ans2=0;
	for(int i = 0 ; i <= n ; ++ i){
		for(int j = 0 ; j < m ; ++ j){
			if(dp[i][j] > ans1)ans1 = dp[i][j], ans2 = m - j;
			else if(dp[i][j] == ans1 && m - j > ans2)ans2 = m - j;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}

