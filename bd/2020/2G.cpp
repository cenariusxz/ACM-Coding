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

int n;
ll a[maxn], b[maxn];
priority_queue<int>q;

int solve(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &b[i]);
	while(!q.empty())q.pop();
	ll sum1 = 0, sum2 = 0;
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		// printf("%lld %lld\n", sum1, sum2);
		sum2 += b[i];
		if(sum1 + a[i] <= sum2){
			ans ++;
			sum1 += a[i];
			q.push(a[i]);
		}
		else if(!q.empty()){
			if(sum1 - q.top() + a[i] <= sum2){
				sum1 = sum1 - q.top() + a[i];
				q.pop();
			}
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)printf("%d\n", solve());
	return 0;
}

