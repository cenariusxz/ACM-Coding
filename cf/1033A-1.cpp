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

int n, ax, ay, bx, by, cx, cy;

int main(){
	scanf("%d%d%d%d%d%d%d", &n, &ax, &ay, &bx, &by, &cx, &cy);
	if((ax - bx > 0) == (ax - cx > 0) && (ay - by > 0) == (ay - cy > 0))printf("YES\n");
	else printf("NO\n");
	return 0;
}

