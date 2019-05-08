#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int n,t,ans = 0;
int a[25];
int sum[25];

void dfs(int m,int s){
	if(m == n){
		ans += (s == t);
		return;	
	}
	if(s > t || s + sum[n] - sum[m] < t)return;
	dfs(m+1, s);
	dfs(m+1, s+a[m+1]);
}

int main(){
	scanf("%d%d",&n,&t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}

