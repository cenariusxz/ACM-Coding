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

ll n,x;
ll a[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &n, &x);
		for(int i = 1 ; i <=n ; ++ i)scanf("%d", &a[i]);
		sort(a + 1, a+1+n);
		ll sum = 0;
		int cnt = 0;
		for(int i = n ; i >= 1 ; -- i){
			if(a[i] >= x)sum += a[i]-x, cnt++;
			if(a[i] < x){
				if(x - a[i] <= sum){
					sum -= x-a[i];
					cnt++;
				}
				else break;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

