#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;

int g[maxn][maxn];
int r[maxn],c[maxn];
int h,w;

ll QP(ll a, ll n){
	ll ans = 1, tmp = a;
	while(n){
		if(n & 1)ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

int main(){
	scanf("%d%d",&h,&w);
	bool flag = 0;
	for(int i = 1 ; i <= h ; ++ i){
		scanf("%d",&r[i]);
		for(int j = 1 ; j <= r[i] ; ++ j)g[i][j] = 1;
		g[i][r[i]+1] = -1;
	}
	for(int j = 1 ; j <= w ; ++ j){
		scanf("%d",&c[j]);
		for(int i = 1 ; i <= c[j] ; ++ i){
			if(g[i][j] == -1)flag = 1;
			g[i][j] = 1;
		}
		if(g[c[j]+1][j] == 1)flag = 1;
		g[c[j]+1][j] = -1;
	}
	if(flag)printf("0\n");
	else{
		ll ans = 1;
		for(int i = 1 ; i <= h ; ++ i){
			for(int j = 1 ; j <= w ; ++ j){
				if(!g[i][j])ans = ans * 2 % mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

