#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3 + 5;
const int maxm = 1e6 + 5;

int n,m;
int num[maxn][maxn];
int a[maxn][maxn];
int ans1,ans2;

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		int nxt = m+1;
		for(int j = m ; j >= 1 ; -- j){
			if(num[i][j])nxt = j;
			a[i][j] = nxt - j;
		}
	}
	for(int j = 1 ; j <= m ; ++ j){
		a[0][j] = -1;
		a[n+1][j] = 0;
		stack<int>s;
		s.push(0);
		for(int i = 1 ; i <= n+1 ; ++ i){
			while(!s.empty() && a[s.top()][j] >= a[i][j]){
				int t = s.top(); s.pop();
				int l = s.top(), r = i;
				ans1 = max(ans1, min(a[t][j], r-l-1));
				ans2 = max(ans2, a[t][j] * (r-l-1));
			}
			s.push(i);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			scanf("%d",&num[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if((i + j) & 1)num[i][j] ^= 1; 
		}
	}
	solve();
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			num[i][j] ^= 1; 
		}
	}
	solve();
	printf("%d\n%d\n",ans1*ans1,ans2);
	return 0;
}

