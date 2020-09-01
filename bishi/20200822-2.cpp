#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;

struct node{
	int id, num;
	bool operator < (const node a)const{
		if(num == a.num)return id < a.id;
		return num > a.num;
	}
}nd[maxn];

int n, m, ans[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i){
		int v, w;
		scanf("%d%d", &v, &w);
		nd[i].id = i;
		nd[i].num = v + 2 * w;
	}
	sort(nd + 1, nd + 1 + n);
	for(int i = 1 ; i <= m ; ++ i)ans[i] = nd[i].id;
	sort(ans + 1, ans + 1 + m);
	for(int i = 1 ; i <= m ; ++ i){
		printf("%d%c", ans[i], i == m ? '\n' : ' ');
	}
	return 0;
}

