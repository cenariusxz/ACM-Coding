#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n;
int pos1[maxn], pos2[maxn];

int main(){
	scanf("%d",&n);
	memset(pos1, -1 , sizeof(pos1));
	memset(pos2, -1 , sizeof(pos2));
	pos1[0] = 0, pos2[0] = 0;
	for(int i = 0 ; i < 2*n ; ++ i){
		int a;
		scanf("%d",&a);
		if(pos1[a] == -1)pos1[a] = i;
		else pos2[a] = i;
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int dis1 = abs(pos1[i] - pos1[i-1]) + abs(pos2[i] - pos2[i-1]);
		int dis2 = abs(pos1[i] - pos2[i-1]) + abs(pos2[i] - pos1[i-1]);
		ans += min(dis1, dis2);
	}
	printf("%lld\n", ans);
	return 0;
}

