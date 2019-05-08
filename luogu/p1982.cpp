#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

ll n,p;
ll a[maxn];
ll dp[maxn],t[maxn],point[maxn];

int main(){
	scanf("%lld%lld",&n,&p);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld",&a[i]);
	t[1] = dp[1] = a[1];
	for(int i = 2 ; i <= n ; ++ i){
		dp[i] = a[i] + max(dp[i-1],0ll);
		t[i] = max(dp[i],t[i-1]);
	}
	if(t[1] >= 0){
		point[1] = t[1] % p;
		point[2] = (t[1] + t[1]) % p;
		for(int i = 2 ; i < n ; ++ i){
			point[i+1] = (t[i] + point[i]) % p;
		}
		printf("%lld\n",point[n]);
	}
	else{
		point[1] = t[1];
		point[2] = t[1] + t[1];
		bool f = 0;
		for(int i = 3 ; i <= n ; ++ i){
			point[i] = point[i-1] + max(t[i-1],0ll);
			if(point[i] >= 0)point[i] %= p;
		}
		ll ans = max(point[1],point[n]);
		if(ans >= 0)printf("%lld\n",ans % p);
		else printf("-%lld\n",abs(ans)%p);
	}
	return 0;
}
