#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;

int a[maxn],n,h;

bool check(int mid){
	int num = 0;
	for(int i = 1 ; i <= n ; ++ i)num += a[i] / mid + (a[i] % mid != 0);
	return num <= h;
}

int main(){
	scanf("%d%d",&n,&h);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int l = 1, r = INF, ans = INF;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = min(ans, mid);
			r = mid-1;
		}
		else l = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}

