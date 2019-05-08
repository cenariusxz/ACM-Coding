#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2e5 + 5;

struct point{
	ll x,y;
	int c;
	bool operator < (const point a)const{
		return x < a.x;
	}
}nd[maxn],que[maxn];

bool cmp(point a, point b){
	return a.y < b.y;
}

int T,n,qcnt;

inline ll min(ll a, ll b){return a <= b ? a : b;}

inline ll get(int i,int j){
	return (que[i].x - que[j].x) * (que[i].x - que[j].x) + (que[i].y - que[j].y) * (que[i].y - que[j].y);
}

ll solve(int l,int r){
	if(l == r)return INF;
	int mid = (l+r) >> 1;
	ll ans = min(solve(l,mid),solve(mid+1,r));
	qcnt = 0;
	for(int i = l ; i <= r ; ++ i){
		if( (nd[mid].x - nd[i].x) * (nd[mid].x - nd[i].x) <= ans)que[++qcnt] = nd[i];
	}
	sort(que + 1, que + 1 + qcnt, cmp);
	for(int i = 1 ; i < qcnt ; ++ i){
		for(int j = i + 1 ; j <= qcnt ; ++ j){
			if( (que[i].y - que[j].y) * (que[i].y - que[j].y) > ans)break;
			if(que[i].c != que[j].c)ans = min(ans, get(i,j));
		}
	}
	return ans;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i){
			scanf("%lld%lld",&nd[i].x,&nd[i].y);
			nd[i].c = 0;
		}
		for(int i = n+1 ; i <= n+n ; ++ i){
			scanf("%lld%lld",&nd[i].x,&nd[i].y);
			nd[i].c = 1;
		}
		sort(nd + 1, nd + 1 + 2*n);
		printf("%.3lf\n",sqrt(1.0*solve(1,2*n)));
	}
	return 0;
}
