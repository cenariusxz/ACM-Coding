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
int sums[maxn], sumt[maxn], dif[maxn];
char s[maxn], t[maxn];


void solve(){
	scanf("%d%s%s", &n, s+1, t+1);
	s[n+1] = t[n+1] = '0';
	n++;
	dif[n+1] = 0;
	for(int i = n ; i >= 1 ; -- i)dif[i] = dif[i+1] + (s[i] != t[i]); 
	for(int i = 1 ; i <= n ; ++ i)sums[i] = sums[i-1] + (s[i] == '0');
	for(int i = 1 ; i <= n ; ++ i)sumt[i] = sumt[i-1] + (t[i] == '1');
	int ans = dif[1];
	for(int i = 1 ; i <= n ; ++ i){
		int tmp = sums[i-1] + (s[i] == '1') + 1 + sumt[i-1] + (t[i] == '0') + dif[i+1];
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}

