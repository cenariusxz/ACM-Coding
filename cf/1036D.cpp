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

int n, m, a[maxn], b[maxn];

int solve(){
	ll sum1 = 0, sum2 = 0;
	int ans = 0, pos1 = 0, pos2 = 0;
	while(pos1 + 1 <= n || pos2 + 1 <= m){
		if(sum1 <= sum2){
			if(pos1 == n)return -1;
			sum1 += a[++pos1];
		}
		else{
			if(pos2 == m)return -1;
			sum2 += b[++pos2];
		}
		if(sum1 == sum2)ans ++, sum1 = sum2 = 0;
	}
	if(sum1 != sum2)return -1;
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d", &b[i]);
	printf("%d", solve());
	return 0;
}

