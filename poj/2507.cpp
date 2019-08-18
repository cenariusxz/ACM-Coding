#include <stdio.h>
#include <algorithm>
#include <math.h>
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
	double x,y,c;
	while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF){
		double l = 0, r = min(x,y);
		for(int i = 0 ; i <= 100 ; ++ i){
			double mid = (l+r)/2;
			double h1 = sqrt(x*x-mid*mid), h2 = sqrt(y*y-mid*mid);
			double cc = h1*h2/(h1+h2);
			if(cc < c)r = mid;
			else l = mid;
		}
		printf("%.3lf\n",l);
	}
	return 0;
}

