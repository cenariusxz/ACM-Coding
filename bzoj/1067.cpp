#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 5e4 + 5;
const int maxm = 1e6 + 6;

int st[maxn<<2],y[maxn],a[maxn];
int n,m;

void build(int o,int l,int r){
	if(l == r){
		st[o] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	st[o] = max(st[o<<1], st[o<<1|1]);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r)return st[o];
	int mid = (l + r) >> 1;
	int ans = -INF;
	if(ql <= mid)ans = max(ans, query(o<<1, l, mid, ql, qr));
	if(qr >= mid+1)ans = max(ans, query(o<<1|1, mid+1, r, ql, qr));
	return ans;
}

int search1(int x){	// >= x  first
	int l = 0, r = n+1, ans = INF;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(y[mid] >= x){
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;		// 1 ~ n or n+1
}

int search2(int x){	// <= x last
	int l = 0, r = n+1, ans = 0;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(y[mid] <= x){
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;		// 0 or 1 ~ n
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&y[i],&a[i]);
	build(1,1,n);
	y[0] = -INF;
	y[n+1] = INF;
	scanf("%d",&m);
	while(m--){
		int from, to;
		scanf("%d%d",&from,&to);
		// from + 1 < to
		if(from + 1 == to)while(1){}
		if(from >= to){
			while(1){}
			printf("true\n");
			continue;	
		}
		int id1 = search1(from), id2 = search2(to);
		if(y[id2] != to){
			// z < to <= from	z < from
			if(y[id1] == from && id2 >= id1 + 1 && a[id1] <= query(1,1,n,id1+1,id2)){
				printf("false\n");
				continue;
			}
			printf("maybe\n");
			continue;
		}
		int flag1 = 0, flag2 = 0;
		if(y[id1] == from){
			if(a[id2] <= a[id1])flag1 = 1;
			else flag1 = -1;
			id1++;
		}
		// id1 ~ id2-1
		if(id1 <= id2-1){
			int Max = query(1,1,n,id1,id2-1);
			if(Max < a[id2] && to - from - 1 == id2-1 - id1 + 1)flag2 = 1;
			else if(Max > a[id2])flag2 = -1;
		}
		//if(to == from+1)flag2 = 1;
		if(flag1 == -1 || flag2 == -1)printf("false\n");
		else if(flag1 == 1 && flag2 == 1)printf("true\n");
		else printf("maybe\n");
	}
	return 0;
}

