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

int a[maxn];
double b[maxn], sum[maxn], Min[maxn];
int n,m;

bool check(double mid){
	for(int i = 1 ; i <= n ; ++ i)b[i] = a[i] - mid;
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + b[i];
	double res = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		Min[i] = min(Min[i-1], sum[i]);
		if(i >= m)res = max(res, sum[i] - Min[i-m]);
	}
	return res >= 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	double l = 0 , r = 2000 , ans = 0;
	// while(fabs(r-l) > 1e-8){
	for(int i = 1 ; i <= 40 ; ++ i){
		double mid = (l+r)/2;
		if(check(mid)){
			ans = max(ans, mid);
			l = mid;
		}
		else r = mid;
	}
	printf("%d\n",(int)(r*1000));
	return 0;
}
