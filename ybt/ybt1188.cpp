#include <bits/stdc++.h>
using namespace std;
const int mod = 1000;
const int maxn = 1e6 + 5;

int f[maxn];

int main(){
	f[1] = f[2] = 1;
	for(int i = 3 ; i <= 1000000 ; ++ i){
		f[i] = (f[i-1] + f[i-2]) % mod;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int a;
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}
