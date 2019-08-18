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

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll tmp = n;
		k = 0;
		while(tmp){
			++ k;
			tmp /= 10;
		}
		bool flag = 0;
		for(int state = 0 ; state < (1<<k) ; ++ state){
			ll res = 0;
			for(int i = k-1 ; i >= 0 ; -- i){
				if(state & (1<<i))res = res * 10 + 7;
				else res = res * 10 + 4;
			}
			//printf("%d %lld\n",state,res);
			if(res > n){
				flag = 1;
				printf("%lld\n",res);
				break;
			}
		}
		if(flag)continue;
		for(int i = 1 ; i <= k+1 ; ++ i)printf("4");
		printf("\n");
	}
	return 0;
}

