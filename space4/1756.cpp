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

int n;
double p[105];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lf", &p[i]);
	sort(p + 1, p + 1 + n);
	if(p[n] >= 0.5)printf("%.12lf\n", p[n]);
	else{
		double p0 = 1, p1 = 0;
		for(int i = n ; i >= 1 ; -- i){
			double np0 = p0 * (1 - p[i]);
			double np1 = p0 * p[i] + p1 * (1-p[i]);
			p0 = np0;
			p1 = np1;
			if(p0 < p1)break;
		}
		printf("%.12lf\n", p1);
	}
	return 0;
}

