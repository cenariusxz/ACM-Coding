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

int n;
ll l,r,num;

ll getsum(int mid){
	if(mid == 0)return 0;
	return (n-(ll)mid+n-1) * (ll)mid;
}

void prt(int st, ll stid){
	ll p1 = (stid+1)/2;
	int p2 = 1 - stid % 2;
	while(1){
		if(p2 == 0){
			printf("%lld ",(ll)st);
			p2 = 1;
		}
		else{
			printf("%lld ", st + p1);
			p1 ++;
			p2 = 0;
		}
		num--;
		if(num == 0 || (p1 == n-st+1))return;
	}
}

void solve(){
	num = r - l +1;
	if(l == n*(ll)(n-1)+1){
		printf("1\n");
		return;
	}
	int left = 1, right = n-1, st = INF;
	while(left <= right){
		int mid = (left + right)/2;
		if(getsum(mid) >= l){st = min(st, mid); right = mid-1;}
		else left = mid+1;
	}
	ll stid = l - getsum(st-1);
	
	for(int i = st; i < n ; ++ i){
		prt(i, stid);
		if(num == 0){
			printf("\n");
			return;
		}
		stid = 1;
	}
	printf("1\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld", &n, &l, &r);
		solve();
	}
	return 0;
}

