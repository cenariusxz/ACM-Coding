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

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		int cnt = 0;
		for(int i = 0 ; i < 61 ; ++ i){
			if(n&(1ll<<i))cnt++;	
		}
		if(cnt == 1)printf("1\n");
		else printf("0\n");
	}
	return 0;
}

