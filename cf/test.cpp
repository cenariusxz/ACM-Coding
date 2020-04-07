#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double INF = 1e60;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int ax, ay, bx, by, tx, ty, n;
int x[maxn], y[maxn];

double cal(int xx, int yy, int id){
	return sqrt((xx - x[id])*1.0*(xx - x[id]) + (yy - y[id])*1.0*(yy - y[id]));
}

int main(){
	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &x[i], &y[i]);
	
	double sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += 2 * cal(tx, ty, i);
	
	double maxa1 = -INF, maxa2 = -INF, maxb1 = -INF, maxb2 = -INF;
	int a1, a2, b1, b2;
	
	for(int i = 1 ; i <= n ; ++ i){
		double dela = cal(tx, ty, i) - cal(ax, ay, i);
		if(dela > maxa1){
			maxa2 = maxa1; a2 = a1;
			maxa1 = dela; a1 = i;
		}
		else if(dela > maxa2)maxa2 = dela, a2 = i;
	}
	
	for(int i = 1 ; i <= n ; ++ i){
		double delb = cal(tx, ty, i) - cal(bx, by, i);
		if(delb > maxb1){
			maxb2 = maxb1; b2 = b1;
			maxb1 = delb; b1 = i;
		}
		else if(delb > maxb2)maxb2 = delb, b2 = i;
	}
	
	double ans = INF;
	ans = min(sum - maxa1, sum - maxb1);
	if(n >= 2){
		if(a1 != b1)ans = min(ans, sum - maxa1 - maxb1);
		else{
			ans = min(ans, sum - maxa1 - maxb2);
			ans = min(ans, sum - maxa2 - maxb1);
		}
	}
	printf("%.15lf\n", ans);
	return 0;
}

