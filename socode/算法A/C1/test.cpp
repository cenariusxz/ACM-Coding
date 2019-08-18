#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;

int a[maxn],sum[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];		// 初始化前缀和数组 
	int ans = INF;		// 答案初始极大值 
	for(int i = 1 ; i <= n ; ++ i){			// 枚举区间左端点 
		for(int j = i ; j <= n ; ++ j){		// 枚举区间右端点 
			int num = sum[j] - sum[i-1];	// 求区间和 
			if(abs(num) < ans)ans = abs(num);	// 尝试用区间和的绝对值更新答案 
		}
	}
	printf("%d\n",ans);
	return 0;
}

