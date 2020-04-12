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

int n, m;
int a[maxn], sum[maxn];

int find(int x){
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) / 2;
		if(sum[mid] == x)return 1;
		else if(sum[mid] > x)r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	int tmp = 0, ans = 0;
	for(int i = 1 ; i <= m ; ++ i){
		int t;
		scanf("%d", &t);
		tmp += t;
		ans += find(tmp);
	}
	printf("%d\n", ans);
	return 0;
}

