#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
double INF = 1e60;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int ax, ay, bx, by, tx, ty, n;
int xx[maxn], yy[maxn];

double cal(int x, int y, int id){
	return sqrt((x-xx[id])*1.0*(x-xx[id]) + (y-yy[id])*1.0*(y-yy[id]));
}

int main(){
	scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty, &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &xx[i], &yy[i]);
	double sum = 0, maxa1 = -INF, maxa2 = -INF, maxb1 = -INF, maxb2 = -INF;
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		sum += cal(tx, ty, i);
		double dela = cal(tx, ty, i) - cal(ax, ay, i);
		if(dela > maxa1){
			maxa2 = maxa1, a2 = a1;
			maxa1 = dela, a1 = i;
		}
		else if(dela > maxa2)maxa2 = dela, a2 = i;
		double delb = cal(tx, ty, i) - cal(bx, by, i);
		if(delb > maxb1){
			maxb2 = maxb1, b2 = b1;
			maxb1 = delb, b1 = i;
		}
		else if(delb > maxb2)maxb2 = delb, b2 = i;
	}
	double ans = min(sum * 2 - maxa1, sum * 2 - maxb1);
	if(n > 1){
		if(a1 != b1)ans = min(ans, sum * 2 - maxa1 - maxb1);
		else ans = min(ans, min(sum * 2 - maxa1 - maxb2, sum * 2 - maxa2 - maxb1));
	}
	printf("%.12lf\n", ans);
	return 0;
}

