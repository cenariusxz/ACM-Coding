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

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, s, k;
		map<int,int> M;
		scanf("%d%d%d", &n, &s, &k);
		for(int i = 1 ; i <= k ; ++ i){
			int a;
			scanf("%d", &a);
			M[a] ++;
		}
		int ans = INF;
		for(int i = s; i <= n ; ++ i){
			if(!M[i]){
				ans = min(ans, i - s);
				break;
			}
		}
		for(int i = s; i >= 1 ; -- i){
			if(!M[i]){
				ans = min(ans, s - i);
				break;
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}

