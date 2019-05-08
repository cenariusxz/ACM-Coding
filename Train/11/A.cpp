#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30010;
typedef long long ll;

int n;
int A[MAXN];
int sum[MAXN];
int vis[MAXN];
int prime[MAXN],pcnt;
ll ans;

void Pre(){
	pcnt = 0;
	for(int i = 2; i <= 30000; ++i){
		if(vis[i] == 0)
			prime[++pcnt] = i;
		for(int j = 1; j * i <= 30000; ++j){
			vis[j * i] = 1;
		}
	}
}

void Single(){
	ans = 0;
	for(int i = 2; i <= n; ++i){
		ans += 1ll * A[i] * (i - 1);
	}
	ll s1 = 0,s2 = ans,s3,s4;
	for(int i = 2; i <= n; ++i){
		s1 += sum[i - 1];
		s2 -= sum[n] - sum[i - 1];
		ans = min(ans,s1 + s2);
	}
}

void Single2(){
	for(int o = 1; o <= pcnt; ++o){
		if(1 + prime[o] > n) break;
		ll s1 = 0,s2 = 0,s3 = 0,s4 = 0;
		int mid = (2 + prime[o]) >> 1;
		int cnt = 0;
		for(int i = 2; i <= mid; ++i){
			cnt++;
			s2 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = prime[o]; i > mid; --i){
			cnt++;
			s3 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = 1 + prime[o] + 1; i <= n; ++i){
			cnt++;
			s4 += 1LL * cnt * A[i];
		}
		ans = min(ans,s1 + s2 + s3 + s4);
		//printf("prime : %d , mid : %d\n",prime[o],mid);
		//printf("1 : %lld %lld %lld %lld\n",s1,s2,s3,s4);
		for(int i = 2; i + prime[o] <= n; ++i){
			s1 += sum[i - 1];
			s2 = s2 - (sum[mid] - sum[i - 1]) + 
				1ll * A[mid + 1] * (mid + 1 - i);
			s3 = s3 - 1ll * A[mid + 1] * (i + prime[o] - 2 - mid)
				+ sum[i + prime[o] - 1] - sum[mid + 1];
			s4 = s4 - (sum[n] - sum[i + prime[o] - 1]);
			ans = min(ans,s1 + s2 + s3 + s4);
			//printf("%d : %lld %lld %lld %lld\n",i,s1,s2,s3,s4);
			mid++;
		}
	}
}

void Single3(){
	for(int o = 1; o <= pcnt; ++o){
		if(prime[o] == 2) continue;
		if(1 + 2 + prime[o] > n) break;
		ll s1 = 0,s2 = 0,s3 = 0,s4 = 0;
		int mid = (6 + prime[o]) >> 1;
		int cnt = 0;
		for(int i = 4; i <= mid; ++i){
			cnt++;
			s2 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = 2 + prime[o]; i > mid; --i){
			cnt++;
			s3 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = 4 + prime[o]; i <= n; ++i){
			cnt++;
			s4 += 1ll * cnt * A[i];
		}
		ans = min(ans,s1 + s2 + s3 + s4 + A[2]);
		for(int i = 2; i + 2 + prime[o] <= n; ++i){
			s1 += sum[i - 1];
			s2 = s2 - (sum[mid] - sum[i + 1]) + 1ll * A[mid + 1] * (mid - i - 1);
			s3 = s3 - 1ll * A[mid + 1] * (i + prime[o] - mid) + sum[i + 1 + prime[o]]
				- sum[mid + 1];
			s4 = s4 - (sum[n] - sum[i + 1 + prime[o]]);
			ans = min(ans,s1 + s2 + s3 + s4 + A[i + 1]);
			mid++;
		}
	}
}

void Single4(){
	for(int o = 1; o <= pcnt; ++o){
		if(prime[o] == 2) continue;
		if(1 + 4 + prime[o] > n) break;
		ll s1 = 0,s2 = 0,s3 = 0,s4 = 0;
		int mid = (6 + prime[o]) >> 1;
		int cnt = 0;
		for(int i = 4; i <= mid; ++i){
			cnt++;
			s2 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = 2 + prime[o]; i > mid; --i){
			cnt++;
			s3 += 1ll * cnt * A[i];
		}
		cnt = 0;
		for(int i = 6 + prime[o]; i <= n; ++i){
			cnt++;
			s4 += 1ll * cnt * A[i];
		}
		ans = min(ans,s1 + s2 + s3 + s4 + A[2] + A[4 + prime[o]]);
		for(int i = 2; i + 4 + prime[o] <= n; ++i){
			s1 += sum[i - 1];
			s2 = s2 - (sum[mid] - sum[i + 1]) + 1ll * A[mid + 1] * (mid - i - 1);
			s3 = s3 - 1ll * A[mid + 1] * (i + prime[o] - mid) + sum[i + 1 + prime[o]]
				- sum[mid + 1];
			s4 = s4 - (sum[n] - sum[i + 3 + prime[o]]);
			ans = min(ans,s1 + s2 + s3 + s4 + A[i + 1] + A[i + 3 + prime[o]]);
			mid++;
		}
	}
}

int main(){
	Pre();
	while(scanf("%d",&n) != EOF && n){
		for(int i = 1; i <= n; ++i){
			scanf("%d",&A[i]);
			sum[i] = sum[i - 1] + A[i];
		}
		// single
		Single();
		//printf("single1 : %lld\n",ans);
		// s - prime - s
		Single2();
		//printf("single2 : %lld\n",ans);
		// s - 2 - prime - s
		Single3();
		//printf("single3 : %lld\n",ans);
		// s - prime - 2 - s
		int mid = (1 + n) >> 1;
		for(int i = 1; i <= mid; ++i) swap(A[i],A[n + 1 - i]);
		for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + A[i];
		Single3();
		//printf("single3 : %lld\n",ans);
		Single4();
		//printf("single4 : %lld\n",ans);
		printf("%lld\n",ans);
	}
	return 0;
}
