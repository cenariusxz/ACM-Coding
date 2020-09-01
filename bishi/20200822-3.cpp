#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int fa[maxn], sum[maxn], n, w[maxn], op[maxn], ans[maxn];

void init(){
	for(int i = 0 ; i <= n + 1 ; ++ i)fa[i] = -1, sum[i] = 0;
}

int find(int x){return x == fa[x] ? x : find(fa[x]);}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &w[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &op[i]);
	init();
	int res = 0;
	for(int i = n ; i >= 1 ; -- i){
		ans[i] = res;
		int id = op[i];
		fa[id] = id, sum[id] = w[id];
		if(fa[id - 1] != -1){
			int rt = find(id - 1);
			sum[id] += sum[rt];
			fa[rt] = id;
		}
		if(fa[id + 1] != -1){
			int rt = find(id + 1);
			sum[id] += sum[rt];
			fa[rt] = id;
		}
		res = max(res, sum[id]);
	}
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d\n", ans[i]);
	}
	return 0;
}

