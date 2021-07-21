#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int m, n;

int main(){
	scanf("%d%d", &m, &n);
	double ans = 0, tmp1 = 0, tmp2 = 0;
	for(int i = 1 ; i <= m ; ++ i){
		tmp2 = pow(i * 1.0 / m, n);
		ans += (tmp2 - tmp1) * i;
		tmp1 = tmp2;
	}
	printf("%.12lf\n", ans);
	return 0;
}

