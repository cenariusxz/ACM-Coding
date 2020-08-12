#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double INF = 1e60;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

struct point{
	double x, y;
	bool operator < (const point a)const{
		return x < a.x;
	}
}nd[maxn], que[maxn];

bool cmp(point a, point b){
	return a.y < b.y;
}

int n, qcnt;

inline double get(int i,int j){
	return sqrt((que[i].x - que[j].x) * (que[i].x - que[j].x) + (que[i].y - que[j].y) * (que[i].y - que[j].y));
}

double solve(int l,int r){
	if(l == r)return INF;
	int mid = (l+r) >> 1;
	double ans = min(solve(l, mid), solve(mid+1, r));
	qcnt = 0;
	for(int i = l ; i <= r ; ++ i){
		if(fabs(nd[mid].x - nd[i].x) < ans)que[++qcnt] = nd[i];
	}
	sort(que + 1, que + 1 + qcnt, cmp);
	for(int i = 1 ; i < qcnt ; ++ i){
		for(int j = i + 1 ; j <= qcnt ; ++ j){
			if(fabs(que[i].y - que[j].y) > ans)break;
			ans = min(ans, get(i, j));
		}
	}
	return ans;
}

int main(){
	while(scanf("%d", &n) && n){
		for(int i = 1 ; i <= n ; ++ i)scanf("%lf%lf", &nd[i].x, &nd[i].y);
		sort(nd + 1, nd + 1 + n);
		printf("%.2lf\n", solve(1, n) / 2);
	}
	return 0;
}
