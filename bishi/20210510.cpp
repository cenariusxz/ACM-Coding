#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[405];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%lld", &a[i]);
	ll x = 100, y = 0;
	for(int i = 1 ; i < n ; ++ i){
		if(a[i+1] > a[i]){
			if(y + x/a[i] <= 100000){
				y += x / a[i];
				x %= a[i];
			}
			else{
				ll t = 100000 - y;
				y = 100000;
				x -= t * a[i];
			}
		}
		else if(a[i+1] < a[i]){
			x += y * a[i];
			y = 0;
		}
	}
	printf("%lld\n", x + y * a[n]);
	return 0;
}

