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

struct node{
	int num, t;	
};
int n, m, vis[maxn];

void solve(){
	queue<node>q;
	q.push(node{n, 0});
	vis[n] = 1;
	while(!q.empty()){
		node u = q.front(); q.pop();
		if(u.num == m){
			printf("%d\n", u.t);
			return;
		}
		if(u.num - 1 && !vis[u.num-1])q.push(node{u.num-1, u.t+1}), vis[u.num-1] = 1;
		if(u.num < m && !vis[u.num*2])q.push(node{u.num*2, u.t+1}), vis[u.num*2] = 1;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	solve();
	return 0;
}

