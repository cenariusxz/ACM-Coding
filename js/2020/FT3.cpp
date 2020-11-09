#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int n, m, a[maxn], b[maxn], L, R, t;
map<int, int>M;
vector<int>V[maxn];
int vis[maxn], que[maxn], qcnt;

int get(int num){
	int l = 0 , r = V[num].size() - 1;
	int first = r , last = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(V[num][mid] >= L)first = mid, r = mid - 1;
		else l = mid + 1;
	}
	l = 0, r = V[num].size() - 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(V[num][mid] <= R)last = mid, l = mid + 1;
		else r = mid - 1;
	}
	return last - first + 1;
}

void solve(){
	qcnt = 0;
	scanf("%d%d%d", &L, &R, &t);
	if(t == 1){
		printf("-1\n");
		return;
	}
	int ans = -1, cnt = (R-L+1)/t, sum = 0;
	for(int i = L ; i < R - cnt + 1 ; ++ i){
		if(vis[a[i]])continue;
		que[++qcnt] = a[i];
		vis[a[i]] = 1;
		// if(a[i] < ans)continue;
		int num = get(a[i]);
		if(num > cnt && a[i] > ans)ans = a[i];
		sum += num;
		if(R-L+1 - sum <= cnt)break;
	}
	if(ans == -1)printf("-1\n");
	else printf("%d\n", b[ans]);
	for(int i = 1 ; i <= qcnt ; ++ i)vis[que[i]] = 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)b[i] = a[i];
	sort(b+1, b+1+n);
	int cnt = unique(b+1, b+n+1) - (b+1);
	for(int i = 1 ; i <= cnt ; ++ i)M[b[i]] = i;
	for(int i = 1 ; i <= cnt ; ++ i)V[i].PB(0);
	for(int i = 1 ; i <= n ; ++ i)a[i] = M[a[i]];
	for(int i = 1 ; i <= n ; ++ i)V[a[i]].PB(i);
	for(int i = 1 ; i <= cnt ; ++ i)V[i].PB(n+1);
	while(m --)solve();
	return 0;
}

