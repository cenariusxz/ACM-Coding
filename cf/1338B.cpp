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

int n;
int head[maxn], point[maxn],nxt[maxn],ind[maxn],size;
int dep[maxn], lef[maxn], sub = 0;

void init(){
	size = 0;
	memset(head, -1 ,sizeof(head));
}

void add(int a,int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
	ind[b] ++;
}

void dfs(int s, int f, int d){
	dep[s] = d;
	int res = 0;
	for(int i = head[s]; ~i ; i = nxt[i]){
		int j = point[i];
		if(j == f)continue;
		if(lef[j])res++;
		dfs(j, s, d+1);
	}
	if(res)sub += res-1;
}

void solve(){
	init();
	for(int i = 1 ; i < n ; ++ i){
		int a,b;
		scanf("%d%d", &a, &b);
		add(a,b);add(b,a);
	}
	int root = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(ind[i] > 1)root = i;
		else lef[i] = 1;
	}
	dfs(root, -1, 1);
	int mn = 0,mx = n-1-sub;
	int odd = 0, even = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(!lef[i])continue;
		if(dep[i] & 1)odd=1;
		else even = 1;
	}
	if(even && odd)mn = 3;
	else mn=1;
	printf("%d %d\n", mn, mx);
}

int main(){
	scanf("%d" , &n);
	solve();
	return 0;
}


