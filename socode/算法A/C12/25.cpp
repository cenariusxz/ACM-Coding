#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll n, ans;
int k = 0;

void dfs(int t, ll sum){
	if(t == k){
		if(sum > n && sum < ans)ans = sum;
		return;
	}
	dfs(t+1, sum*10+4);
	dfs(t+1, sum*10+7);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll tmp = n;
		ans = INF;
		k = 0;
		while(tmp){
			++ k;
			tmp /= 10;
		}
		dfs(0,0);
		if(ans != INF)printf("%lld\n",ans);
		else{
			for(int i = 1 ; i <= k+1 ; ++ i)printf("4");
			printf("\n");	
		}
		//++ k;
		//dfs(0,0);
		//printf("%lld\n",ans);
	}
	return 0;
}

