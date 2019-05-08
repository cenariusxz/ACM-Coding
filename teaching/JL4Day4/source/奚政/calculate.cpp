#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("calculate.in","r",stdin);
	freopen("calculate.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ans = 0;
	while(n > 1){
		ans++;
		n >>= 1;
	}
	printf("%d\n",ans);
	return 0;
}
