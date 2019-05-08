#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int p[maxn];
int pos[2][maxn];
int cnt[2];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= 2*n ; ++ i)scanf("%d",&p[i]);
	for(int i = 1 ; i <= 2*n ; ++ i)pos[p[i]][++cnt[p[i]]] = i;
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i)ans += abs(pos[0][i] - pos[1][i]);
	printf("%d\n",ans);
	return 0;
}
