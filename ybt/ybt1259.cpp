#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n;
int a[205],dp[205],pre[205];

int main(){
	scanf("%d",&n);
	for(int i = n ; i >= 1 ; -- i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		dp[i] = 1;
		pre[i] = 0;
		for(int j = 1 ; j < i ; ++ j){
			if(a[j] >= a[i] && dp[j] + 1 > dp[i])dp[i] = dp[j]+1, pre[i] = j;	
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(dp[i] > dp[ans])ans = i;	
	}
	printf("max=%d\n",dp[ans]);
	while(ans){
		printf("%d ",a[ans]);
		ans = pre[ans];
	}
	
	return 0;
}

