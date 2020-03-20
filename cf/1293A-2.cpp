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

// map abs sort bsearch
int n, s, k;
int a[maxn];

bool bsearch(int x){
	int l = 1, r = k;
	while(l <= r){
		int m = (l+r) / 2;
		if(a[m] == x)return 1;
		if(a[m] > x)r = m-1;
		else l = m+1;
	}
	return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &s, &k);
		for(int i = 1 ; i <= k ; ++ i){
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+k);
		int ans = INF;
		for(int i = s ; i <= n ; ++ i){
			if(bsearch(i) == 0){
				ans = min(ans, i-s);
				break;	
			}
		}
		for(int i = s ; i >= 1 ; -- i){
			if(bsearch(i) == 0){
				ans = min(ans, s-i);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

