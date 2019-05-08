#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[80];

int main(){
	f[0] = f[1] = 1; f[2] = 2;
	for(int i = 3 ; i <= 70 ; ++ i)f[i] = f[i-1] + f[i-2] + f[i-3];
	int n;
	while(scanf("%d",&n)&&n){
		printf("%lld\n",f[n]);
	}
	return 0;
}
