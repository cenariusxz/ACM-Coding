#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n, k;
int a[maxn], num[maxn], cntl[maxn], cntr[maxn], cnt;
ll suml[maxn], sumr[maxn], ans = INF;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] == a[i-1])num[cnt] ++;
		else{
			a[++cnt] = a[i];
			num[cnt] = 1;
		}
		if(num[cnt] >= k){
			printf("0\n");
			return 0;
		}
	}
	n = cnt;
	
	for(int i = 1 ; i <= n ; ++ i){
		cntl[i] = cntl[i-1] + num[i];
		suml[i] = suml[i-1] + num[i] * (ll)a[i];
		if(cntl[i] >= k){
			ll res = cntl[i-1] * (ll)(a[i]-1) - suml[i-1] + (k - num[i]);
			if(res < ans)ans = res;
		}
	}
	
	for(int i = n ; i >= 1 ; -- i){
		cntr[i] = cntr[i+1] + num[i];
		sumr[i] = sumr[i+1] + num[i] * (ll)a[i];
		if(cntr[i] >= k){
			ll res = sumr[i+1] - cntr[i+1] * (ll)(a[i]+1) + (k - num[i]);
			if(res < ans)ans = res;
		}
	}
	
	for(int i = 2 ; i < n ; ++ i){
		ll res1 = cntl[i-1] * (ll)(a[i]-1) - suml[i-1];
		ll res2 = sumr[i+1] - cntr[i+1] * (ll)(a[i]+1);
		ll res = res1 + res2 + (k - num[i]);
		if(res < ans)ans = res;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}

