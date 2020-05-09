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

int l, r, k, f[maxm], g[maxm], sum[maxm][10];

void solve(){

}

void init(){
	for(int i = 1 ; i <= 1000000 ; ++ i){
		int s = i;
		f[i] = 1;
		while(s){
			if(s % 10)f[i] *= s % 10;
			s /= 10;
		}
	}
	for(int i = 1 ; i <= 1000000 ; ++ i){
		if(i < 10)g[i] = i;
		else g[i] = g[f[i]];
	}
	for(int i = 1 ; i <= 1000000 ; ++ i){
		for(int j = 1 ; j <= 9 ; ++ j)sum[i][j] = sum[i-1][j];
		sum[i][g[i]]++;
	}
}

int main(){
	init();
	int Q;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", sum[r][k] - sum[l-1][k]);
	}
	return 0;
}

