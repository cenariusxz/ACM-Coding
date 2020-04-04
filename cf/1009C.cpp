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

int n,m;

int main(){
	scanf("%d%d", &n, &m);
	double ans = 0;
	ll sumx = 0, sumd1 = 0, sumd2 = 0, sumd3 = 0;
	
	//sumx + sumd1 * (n-1) / 2 + sumd2 * (n+1) * (n-1) / n / 4 + sumd3 * n / 4
	
	while(m--){
		ll x,d;
		scanf("%lld%lld", &x, &d);
		sumx += x;
		if(d >= 0)sumd1 += d;
		else{
			if(n & 1)sumd2 += d;
			else sumd3 += d;
		}
	}
	
	ans = sumx + sumd1 * (n-1) / 2.0 + sumd2 * (n+1) * (n-1) / 4.0 / n + sumd3 * n / 4.0;
	
	printf("%.15lf\n", ans);
	return 0;
}

