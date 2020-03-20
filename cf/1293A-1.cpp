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

void solve(){
	a[0] = 0;
	a[++k] = n+1;
	int id = 0;
	for(int i = 1 ; i <= k ; ++ i){
		if(a[i] > s){
			printf("0\n");
			return;	
		}
		if(a[i] == s){
			id = i;
			break;	
		}
	}
	int ans = INF;
	for(int i = id ; i < k ; ++ i){
		if(a[i+1] != a[i] + 1){
			ans = min(ans, (a[i]+1) - s);
			break;
		}
	}
	for(int i = id ; i > 0 ; -- i){
		if(a[i-1] != a[i] - 1){
			ans = min(ans, s - (a[i]-1));
			break;
		}
	}
	printf("%d\n",ans);
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
		solve();
	}
	return 0;
}

