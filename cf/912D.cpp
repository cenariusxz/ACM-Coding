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

struct node{
	int x, y;
	ll t;
	bool operator < (const node a)const{
		return t < a.t;
	}
};

int n, m, r, k;
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
map<int, int> M[maxn];

ll get(int x, int y){
	return (min(x, n+1-r) - max(1, x+1-r) + 1) * (ll)(min(y, m+1-r) - max(1, y+1-r) + 1);
}

priority_queue<node>q;

int main(){
	scanf("%d%d%d%d", &n, &m, &r, &k);
	q.push(node{(n+1)/2, (m+1)/2, get((n+1)/2, (m+1)/2)});
	M[(n+1)/2][(m+1)/2] = 1;
	double ans = 0;
	while(!q.empty()){
		node u = q.top(); q.pop();
		ans += u.t * 1.0 / (n-r+1) / (m-r+1);
		-- k;
		if(!k)break;
		for(int i = 0 ; i < 4 ; ++ i){
			int dx = u.x + xx[i], dy = u.y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m || M[dx][dy])continue;
			q.push(node{dx, dy, get(dx, dy)});
			M[dx][dy] = 1;
		}
	}
	printf("%.12lf\n", ans);
	return 0;
}

