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

int n, a[maxn], b[maxn], vis[maxn];
stack<int>S;

void solve(){
	for(int i = n ; i >= 1 ; -- i)S.push(a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[b[i]])printf("0 ");
		else{
			int ans = 0;
			while(!S.empty()){
				int now = S.top(); S.pop();
				vis[now] = 1;
				ans ++;
				if(now == b[i])break;
			}
			printf("%d ", ans);
		}
	}
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &b[i]);
	solve();
	return 0;
}


