#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n,m;
int a[maxn];

void solve(){
	int p;
	scanf("%d",&p);
	int ans1 = -INF, ans2 = INF;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(a[mid] <= p){
			ans1 = max(ans1, a[mid]);
			l = mid+1;
		}
		else r = mid-1;
	}
	l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(a[mid] >= p){
			ans2 = min(ans2, a[mid]);
			r = mid-1;
		}
		else l = mid+1;
	}
	if(p - ans1 <= ans2 - p)printf("%d\n",ans1);
	else printf("%d\n",ans2);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1, a+1+n);
	scanf("%d",&m);
	while(m--)solve();
	return 0;
}

