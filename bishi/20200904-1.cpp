#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int n, a, b, c, d;
ll C[105][105];

void init(){
    for(int i = 0 ; i <= 105 ; ++ i){
        for(int j = 0 ; j <= i ; ++ j){
            C[i][j] = (i == 0 || j == 0) ? 1 : (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}

int main(){
	init();
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	n *= n;
	ll res = C[n][a] * C[n-a][b] % mod * C[n-a-b][c] % mod;
	printf("%lld\n", res);
	return 0;
}

