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

int n, k, sg[105];

int sg_odd(int x){
	if(x == 0)return 0;
	if(x == 1)return 1;
	if(x == 2)return 0;
	if(x == 3)return 1;
	if(x == 4)return 2;
	if(x & 1)return 0;
	if(sg_odd(x/2) == 1)return 2;
	return 1;
	/*
	if(~sg[x])return sg[x];	
	int vis[105];
	memset(vis, 0, sizeof(vis));
	vis[sg_odd(x-1)] = 1;
	if(x % 2 == 0)vis[sg_odd(x/2)] = 1;
	for(int i = 0 ; ; ++ i){
		if(vis[i])continue;
		return sg[x] = i;
	}*/
}

int sg_even(int x){
	if(x == 0)return 0;
	if(x == 1)return 1;
	if(x == 2)return 2;
	if(x & 1)return 0;
	return 1;
	/*
	if(~sg[x])return sg[x];
	int vis[105];
	memset(vis, 0, sizeof(vis));
	vis[sg_even(x-1)] = 1;
	if(x % 2 == 0)vis[0] = 1;
	for(int i = 0 ; ; ++ i){
		if(vis[i])continue;
		return sg[x] = i;
	}*/
}

void solve(){
	/*
	memset(sg, -1, sizeof(sg));
	sg[0] = 0;
	for(int i = 1 ; i <= 100 ; ++ i){
		//if(sg_odd(i) == 2)printf("%d\n", i);
		//printf("%d : %d\n", i, sg_odd(i));
		if(i % 2 == 0)printf("%d : %d %d\n", i, sg_odd(i), sg_odd(i/2));
	}*/
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d", &a);
		if(k & 1)ans ^= sg_odd(a);
		else ans ^= sg_even(a);
	}
	if(ans)printf("Kevin\n");
	else printf("Nicky\n");
}

int main(){
	scanf("%d%d", &n, &k);
	solve();
	return 0;
}

