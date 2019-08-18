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

int a[maxn]; 

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	while(m--){
		int x;
		scanf("%d",&x);
		int l = 1, r = n, ans = -1;
		while(l <= r){
			int mid = (l + r)>>1;
			if(a[mid] == x){
				ans = mid;
				break;
			}
			else if(a[mid] < x)l = mid+1;
			else r = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

