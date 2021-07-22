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

int n, m;
int a[maxn], b[maxn];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d", &b[i]);
	for(int i = 1 ; i <= m ; ++ i)b[i] = 1 << b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int ans = 0, pos = 1;
	for(int i = 1 ; i <= m ; ++ i){
		while(a[pos] < b[i] && pos < n)++pos;
		if(a[pos] < b[i])break;
		ans ++;
		a[pos] -= b[i];
	}
	printf("%d\n", ans);
	return 0;
}

