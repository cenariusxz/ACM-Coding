#include <bits/stdc++.h>
using namespace std;
const int mod = 12345;

int main(){
	int n;
	scanf("%d",&n);
	int pre_odd = 1, pre_even = 8;	//1digit
	for(int i = 2 ; i <= n ; ++ i){
		int now_odd = (pre_odd*9 + pre_even*1) % mod;
		int now_even = (pre_odd*1 + pre_even*9) % mod;
		pre_odd = now_odd;
		pre_even = now_even;
	}
	printf("%d\n",pre_even);
	return 0;
}
