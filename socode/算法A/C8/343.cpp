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
	double x;
	scanf("%lf",&x);
	double l = 0, r = 1e6;
	for(int i = 1 ; i <= 100 ; ++ i){
		double mid = (l+r)/2;
		if(mid*mid > x)r = mid;
		else l = mid;	
	}
	printf("%.5lf\n",l);
	return 0;
}

