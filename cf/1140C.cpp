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

int k, n;
struct node{
	int t, b;
	bool operator < (const node x)const{
		return b > x.b;
	}
}nd[maxn];
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d", &nd[i].t, &nd[i].b);
	sort(nd + 1, nd + 1 + n);
	ll ans = -1, sum = 0;
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(cnt < k){
			q.push(nd[i].t);
			cnt++;
			sum += nd[i].t;
		}
		else if(q.top() < nd[i].t){
			int tmp = q.top(); q.pop();
			q.push(nd[i].t);
			sum = sum - tmp + nd[i].t;
		}
		ll res = sum * nd[i].b;
		if(res > ans)ans = res;
	}
	printf("%lld\n", ans);
	return 0;
}

