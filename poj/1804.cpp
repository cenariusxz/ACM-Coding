#include <stdio.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

int n,a[maxn];
int tmp[maxn];

ll solve(int l,int r){
	if(l == r)return 0;
	int mid = (l + r) >> 1;
	ll ans = solve(l,mid) + solve(mid+1,r);
	int p1 = l, p2 = mid+1, cnt = 0, num = 0;
	while(p1 <= mid && p2 <= r){
		if(a[p1] <= a[p2]){
			if(cnt == 0 || a[p1] != tmp[cnt])num = 0;
			tmp[++cnt] = a[p1];
			++p1;
			ans += p2 - mid - 1 - num;
		}
		else{
			if(cnt == 0 || a[p2] != tmp[cnt])num = 0;
			tmp[++cnt] = a[p2];
			++p2;
			++num;
		}
	}
	while(p1 <= mid){
		if(cnt == 0 || a[p1] != tmp[cnt])num = 0;
		tmp[++cnt] = a[p1];
	  	++p1;
		ans += p2 - mid - 1 - num;
	}
	while(p2 <= r)tmp[++cnt] = a[p2++];
	for(int i = 1 ; i <= cnt ; ++ i)a[l + i - 1] = tmp[i];
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q = 1 ; q <= T ; ++ q){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
		printf("Scenario #%d:\n",q);
		printf("%lld\n\n",solve(1,n));
	}
	return 0;
}
