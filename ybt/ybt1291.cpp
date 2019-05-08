#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,t;
int a[25];
int dp[1005];

int main(){
	scanf("%d%d",&n,&t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = t ; j >= a[i]; -- j){
			dp[j] += dp[j-a[i]];	
		}
	}
	printf("%d\n",dp[t]);
	return 0;
}

