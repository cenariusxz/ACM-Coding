#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef long long ll;

ll m,n;

int main(){
	while(cin >> m >> n){
		if(m == 0 && n == 0) break;
		ll t = min(m,n);
		if(t % 2 == 0) t--;
		ll ans = 0;
		ll t1 = (t - 1) / 2LL;
		ll s1 = (1 + t) * ((t - 1) / 2LL + 1) / 2LL;
		ll s2 = (t * (t + 1) * (2 * t + 1)) / 6LL
			- 2LL * (t1 * (t1 + 1) * (2 * t1 + 1)) / 3LL;
		ll s3 = (t * t * (t + 1) * (t + 1)) / 4LL
			- 2LL * (t1 * t1 * (t1 + 1) * (t1 + 1));
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		ans = -2LL * s2 + m * n * s1 - 
			s2 * (m + n) + s1 * (m + n + 1) + s3;
		cout << ans << endl;
	}
	return 0;
}
