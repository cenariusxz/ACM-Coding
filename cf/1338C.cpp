#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int res[105] = {0,1,2,3,4,8,12,5,10,15,6,11,13,7,9,14};
int bit[105];

ll n;

void solve(){
	if(n <= 15){
		printf("%d\n", res[n]);
		return;
	}
	int k = 0;
	for(k = 4 ; ; k += 2){
		if(n <= (1ll<<(k+2))-1)break;
	}
	ll grp = (n - (1ll<<k))/3;
	int id = (n - (1ll<<k)) % 3;
	ll s = (1ll<<k)+grp;
	for(int i = k+2 ; i >= 1 ; -- i){
		bit[i] = s & 1;
		s >>= 1;
	}

	if(id == 0){
		printf("%lld\n",(1ll<<k)+grp);
		return;
	}
	else if(id == 1){
		for(int i = 1 ; i <= k+2 ; i += 2){
			if(2*bit[i]+bit[i+1] == 0)bit[i] = 0, bit[i+1]=0;
			else if(2*bit[i]+bit[i+1] == 1)bit[i] = 1, bit[i+1]=0;
			else if(2*bit[i]+bit[i+1] == 2)bit[i] = 1, bit[i+1]=1;
			else if(2*bit[i]+bit[i+1] == 3)bit[i] = 0, bit[i+1]=1;
		}
	}
	else{
		for(int i = 1 ; i <= k+2 ; i += 2){
			if(2*bit[i]+bit[i+1] == 0)bit[i] = 0, bit[i+1]=0;
			else if(2*bit[i]+bit[i+1] == 1)bit[i] = 1, bit[i+1]=1;
			else if(2*bit[i]+bit[i+1] == 2)bit[i] = 0, bit[i+1]=1;
			else if(2*bit[i]+bit[i+1] == 3)bit[i] = 1, bit[i+1]=0;
		}
	}
	ll ans = 0;
	for(int i = 1 ; i <= k+2 ; ++ i)ans = ans * 2 + bit[i];
	printf("%lld\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &n);
		solve();
	}
	return 0;
}


