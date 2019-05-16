#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

int a[maxn];
int n,k,ans = 0;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 2 ; i <= n ; ++ i){
		if(a[i] + a[i-1] < k){
			ans += k - a[i] - a[i-1];
			a[i] = k - a[i-1];
		}
	}
	printf("%d\n",ans);
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
