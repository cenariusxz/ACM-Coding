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

int n, k;
int del[maxn], sk[maxn], num[maxn];

void solve(){
	while(k --){
		int a, b;
		scanf("%d%d", &a, &b);
		if(sk[a] > sk[b])del[a] ++;
		if(sk[b] > sk[a])del[b] ++;
	}
	for(int i = 1 ; i <= n ; ++ i)num[i] = sk[i];
	sort(num + 1, num + 1 + n);
	num[0] = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		int l = 0, r = n, ans = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(num[mid] < sk[i])ans = max(ans, mid), l = mid + 1;
			else r = mid - 1;
		}
		printf("%d ", ans - del[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &sk[i]);
	solve();
	return 0;
}

