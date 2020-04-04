#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
const int maxm = 1e6 + 5;

struct node{
	int l, r, id;
	bool operator < (const node x)const{
		if(l == x.l)return r > x.r;
		return l < x.l;
	}
}nd[maxn];

int n;

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].l, &nd[i].r);
	for(int i = 1 ; i <= n ; ++ i)nd[i].id = i;
	sort(nd + 1, nd + 1 + n);
	nd[0].l = nd[0].r = -INF;
	for(int i = 2 ; i <= n ; ++ i){
		if(nd[i-1].r >= nd[i].r){
			printf("%d %d\n", nd[i].id, nd[i-1].id);
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}

