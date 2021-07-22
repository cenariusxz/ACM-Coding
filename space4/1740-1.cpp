#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

ll C[1015][1015];
int k, c[1015];

void init(){
    for(int i=0;i<=1005;++i){
        for(int j=0;j<=i;++j){
            C[i][j] = (i&&j) ? (C[i-1][j]+C[i-1][j-1])%mod : 1;
        }
    }
}

int main(){
	init();
	scanf("%d", &k);
	for(int i = 1 ; i <= k ; ++ i)scanf("%d", &c[i]);
	int sum = 0;
	for(int i = 1 ; i <= k ; ++ i)sum += c[i];
	ll ans = 1;
	for(int i = k ; i >= 1 ; -- i){
		ans = ans * C[sum-1][c[i]-1] % mod;
		sum -= c[i];
	}
	printf("%lld\n", ans);
	return 0;
}

