#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 6;

int n, x, y, a[maxn], b[maxn], g[maxn], k[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
	}
	scanf("%d%d",&x,&y);
	int ans = -1;
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] <= x && x <= a[i] + g[i] && b[i] <= y && y <= b[i] + k[i]){
			ans = i;
		}
	}
	printf("%d\n",ans);
	return 0;
}


