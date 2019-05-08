#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n,m,t;
int a[maxn];

int main(){
	freopen("search.in","r",stdin);
	freopen("search.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	while(t--){
		scanf("%d",&m);
		int l = 1, r = n, ans = -1;
		while(l <= r){
			int mid = (l+r) >> 1;
			if(a[mid] <= m){
				ans = max(ans,a[mid]);
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
