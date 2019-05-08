#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	scanf("%d",&k);
	int ans = 0,day = 0;
	for(int i = 1 ; i <= k ; ++ i){
		if(day + i >= k){
			ans += (k - day) * i;
			break;
		}
		ans += i * i;
		day += i;
	}
	printf("%d\n",ans);
	return 0;
}
