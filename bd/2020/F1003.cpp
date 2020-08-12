#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, l, k;
ll a[maxn];

void solve(){
	sort(a + 1 , a + 1 + n, greater<ll>() );
	int cnt = n - l + 1;
	ll amax = 0, amin = 0;
	int num = 0, st = 0;
	while(num < cnt){
		if(cnt - num <= l - k + 1){
			amax += a[st + k] * (cnt - num);
			break;
		}
		else amax += a[st + k] * (l - k + 1);
		num += l - k + 1;
		if(cnt - num <= k - 1){
			for(int i = 1 ; i <= cnt - num ; ++ i){
				amax += a[st + k + i];
			}
			break;
		}
		else{
			for(int i = 1 ; i <= k - 1 ; ++ i){
				amax += a[st + k + i];
			}
		}
		num += k - 1;
		st += k;
	}
	
	sort(a + 1 , a + 1 + n);
	
	num = 0, st = 0;
	while(num < cnt){
		if(cnt - num <= k){
			amin += a[st + l - k + 1] * (cnt - num);
			break;
		}
		else amin += a[st + l - k + 1] * k;
		num += k;
		if(cnt - num <= l - k){
			for(int i = 1 ; i <= cnt - num; ++ i){
				amin += a[st + l - k + 1 + i];
			}
			break;
		}
		else{
			for(int i = 1 ; i <= l - k; ++ i){
				amin += a[st + l - k + 1 + i];
			}
		}
		num += l - k;
		st += l - k + 1;
	}
	
	printf("%lld %lld\n", amax, amin);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &l, &k);
		for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
		solve();
	}
	return 0;
}

