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

int solve(){
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	if(n < m)return 0;
	int a = ceil(m * p / 100.0);
	return (n - m) / a + 1;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)printf("%d\n", solve());
	return 0;
}

