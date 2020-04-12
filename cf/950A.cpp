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

int main(){
	int l,r,a;
	scanf("%d%d%d", &l, &r, &a);
	if(l > r)swap(l, r);
	if(l + a <= r)printf("%d\n", (l+a) * 2);
	else printf("%d\n", (l+r+a) / 2 * 2);
	return 0;
}

