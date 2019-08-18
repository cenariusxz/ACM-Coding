#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;		// 约 4*(10^18) 
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll n, ans;	// ans > n 的最小数 
int k;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		k = 0;
		ll tmp = n;
		while(tmp){
			k++;
			tmp /= 10;
		}
		ans = INF;
		
		for(int state = 0 ; state < (1<<k) ; ++state){
			ll sum = 0;
			for(int i = k-1 ; i >= 0 ; -- i){
				if(state & (1<<i))sum = sum * 10 + 7;
				else sum = sum * 10 + 4;
			}
			if(sum > n)ans = min(ans, sum);
		}
		
		if(ans != INF)printf("%lld\n",ans);
		else{
			for(int i = 1 ; i <= k + 1 ; ++ i)printf("4");
			printf("\n");
		}
	}
	return 0;
}

