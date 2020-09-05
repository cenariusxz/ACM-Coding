#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

struct node{
	int p, w, v;
	bool operator < (const node a)const{
		if(v == a.v && p == a.p)return w < a.w;
		if(v == a.v)return p < a.p;
		return v > a.v;
	}
}nd[maxn];

int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d%d", &nd[i].p, &nd[i].w, &nd[i].v);
	sort(nd + 1, nd + 1 + n);
	int ans = 0, nowm = 0, nowk = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(nowm + nd[i].w > m || nowk + nd[i].p > k)continue;
		nowm += nd[i].w;
		nowk += nd[i].p;
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}

