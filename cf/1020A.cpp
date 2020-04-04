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

int n, h, a, b, k;

int main(){
	scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
	while(k--){
		int ta, fa, tb, fb;
		scanf("%d%d%d%d", &ta, &fa, & tb, &fb);
		if(ta == tb)printf("%d\n", abs(fa - fb));
		else{
			int ans = abs(ta - tb);
			int pass = 0;
			if(fa < a)pass = a;
			else if(fa > b)pass = b;
			else pass = fa;
			ans += abs(fa - pass) + abs(fb - pass);
			printf("%d\n", ans);
		}
	}
	return 0;
}

