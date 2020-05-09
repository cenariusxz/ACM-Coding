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

int n;
char ss[55];
string s[55];

void solve(){
	s[0] = s[1];
	int len = s[0].length();
	for(int i = 0 ; i <= n ; ++ i)s[i] = s[i] + s[i];
	int ans = INF;
	for(int i = 0 ; i < len ; ++ i){
		int res = 0;
		int num = 0;
		for(int j = 1 ; j <= n ; ++ j){
			for(int k = 0 ; k < len ; ++ k){
				if(s[j].substr(k, len) == s[0].substr(i, len)){
					res += k;
					num++;
					break;
				}
			}
		}
		if(num < n){
			printf("-1\n");
			return;
		}
		ans = min(ans, res);
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", ss);
		s[i] = string(ss);
	}
	solve();
	return 0;
}

