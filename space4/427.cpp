#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 5;
const int maxm = 1e6 + 6;

int n, q, pcnt, nsum;
int a[maxn], cnt[maxn], vis[maxn], p[maxn];

void getP(int num){
	pcnt = 0;
	for(int i = 2 ; i * (ll)i <= num ; ++ i){
		if(num % i == 0){
			p[pcnt++] = i;
			while(num % i == 0)num /= i;
		}
	}
	if(num > 1)p[pcnt++] = num;
}

ll del(int ind){
	vis[ind] --;
	nsum --;
	if(a[ind] == 1){
		cnt[1] --;
		return nsum;
	}
	getP(a[ind]);
	ll res = 0;
	for(int i = 1 ; i < (1 << pcnt) ; ++ i){
		int tmp = 1;
		int bits = 0;
		for(int j = 0 ; j < pcnt ; ++ j){
			if(i & (1 << j))tmp *= p[j], ++ bits;
		}
		cnt[tmp] --;
		if(bits & 1)res += cnt[tmp];
		else res -= cnt[tmp];
	}
	return nsum - res;
}

ll add(int ind){
	vis[ind] ++;
	nsum ++;
	if(a[ind] == 1){
		cnt[1] ++;
		return nsum - 1;
	}
	getP(a[ind]);
	ll res = 0;
	for(int i = 1 ; i < (1 << pcnt) ; ++ i){
		int tmp = 1;
		int bits = 0;
		for(int j = 0 ; j < pcnt ; ++ j){
			if(i & (1 << j))tmp *= p[j], ++ bits;
		}
		if(bits & 1)res += cnt[tmp];
		else res -= cnt[tmp];
		cnt[tmp] ++;
	}
	return nsum - 1 - res;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	ll ans = 0;
	while(q--){
		int ind;
		scanf("%d", &ind);
		if(vis[ind])ans -= del(ind);
		else ans += add(ind);
		//for(int i = 1 ; i <= 6 ; ++ i)printf("T: %d ", cnt[i]);
		//printf("\n");
		printf("%lld\n", ans);
	}
	return 0;
}

