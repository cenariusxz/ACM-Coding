#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int k,n;
	while(scanf("%d%d",&k,&n)!=EOF){
		ll tmp = 1,ans = 0;
		while(n){
			if(n & 1)ans += tmp;
			tmp = tmp * k;
			n >>= 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}