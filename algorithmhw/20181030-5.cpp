#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

struct node{
	double stx,edx;
	int val;
	bool operator < (const node x)const{
		return edx < x.edx;
	}
}nd[maxn];
int dp[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lf%lf%d",&nd[i].stx,&nd[i].edx,&nd[i].val);
	}
	sort(nd+1, nd+1+n);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j < i ; ++ j){
			if(nd[j].edx >= nd[i].stx)break;
			dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += nd[i].val;
		ans = max(ans, dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
