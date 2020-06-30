#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
int n;
int st[maxn << 2][2], vis[maxn], num[maxn];
int head[maxn], point[maxn], nxt[maxn], idl[maxn], size;
vector<int>V[maxn], vv[2];
int stx[maxn], edx[maxn], cnt;

void build(int o, int l, int r){
	if(l == r){
		st[o][0] = st[o][1] = INF;
		st[o][num[l]] = l;
		return;
	}
	int m = (l + r) >> 1;
	build(o<<1, l, m);
	build(o<<1|1, m+1, r);
	st[o][0] = min(st[o<<1][0], st[o<<1|1][0]);
	st[o][1] = min(st[o<<1][1], st[o<<1|1][1]);
}

void update(int o, int l, int r, int ind){
	if(l == r){
		st[o][0] = st[o][1] = INF;
		return;
	}
	int m = (l + r) >> 1;
	if(ind <= m)update(o<<1, l, m, ind);
	else update(o<<1|1, m+1, r, ind);
	st[o][0] = min(st[o<<1][0], st[o<<1|1][0]);
	st[o][1] = min(st[o<<1][1], st[o<<1|1][1]);
}

int query(int o, int l, int r, int ql, int qr, int x){
	if(ql <= l && qr >= r)return st[o][x];
	int m = (l + r) >> 1, ans = INF;
	if(ql <= m)ans = min(ans, query(o<<1, l, m, ql, qr, x));
	if(qr >= m+1)ans = min(ans, query(o<<1|1, m+1, r, ql, qr, x));
	return ans;
}

void presolve(){
	n = strlen(s+1);
	for(int i = 1 ; s[i] ; ++ i)num[i] = s[i] == 'L' ? 0 : 1;
	build(1, 1, n);
	//printf("aaaaaa\n");
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		cnt ++;
		int pre = i, x = num[i] ^ 1;
		V[cnt].PB(pre); stx[cnt] = num[pre];
		while(1){
			int pos = query(1, 1, n, pre+1, n, x);
			if(pos == INF)break;
			V[cnt].PB(pos); edx[cnt] = num[pos];
			pre = pos; x ^= 1;
		}
		for(int i = 0 ; i < V[cnt].size() ; ++ i)update(1, 1, n, V[cnt][i]);
		for(int i = 0 ; i < V[cnt].size() ; ++ i)vis[V[cnt][i]] = 1;
		//for(int i = 0 ; i < V[cnt].size() ; ++ i)printf("%d ", V[cnt][i]);
		//printf("\n");
	}
	//printf("%d\n", cnt);
}

void init(){
	memset(head, -1, sizeof(head));
	size = 0;
}

void add(int a, int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void getans(){
	init();
	for(int i = 1 ; i <= cnt ; ++ i){
		if(stx[i] == 0)add(0, i);
		else add(cnt+1, i);
		if(edx[i] == 0)add(i, 0);
		else add(i, cnt+1);
	}
	
}

void solve(){
	presolve();
	getans();
}

int main(){
	scanf("%s", s+1);
	solve();
	return 0;
}

