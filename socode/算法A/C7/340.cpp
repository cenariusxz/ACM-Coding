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

int my_lower_bound(int a[], int start, int end, int x) {
    // write your code here.
    // a: 升序数组
    // start: 要查找的起点下标
    // end: 要查找的终点下标
    // x: 要查找的数字
    // return 第一个>= x 的数字的下标。
    int l = start, r = end, ans = INF;
    while(l <= r){
    	int mid = (l+r) >> 1;
		if(a[mid] >= x){
			ans = min(ans, mid);
			r = mid-1;
		}
		else l = mid+1;
    }
    return ans;
}

int a[maxn];

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i = 0 ; i < n ; ++ i)scanf("%d",&a[i]);
	while(q--){
		int x;
		scanf("%d",&x);
		int ans = my_lower_bound(a,0,n-1,x);
		if(ans == INF)ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}

