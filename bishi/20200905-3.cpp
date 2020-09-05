#include <bits/stdc++.h>
using namespace std;
typedef long long ll;;
const int maxn = 2e5 + 5;

int n, a[maxn];
double l[maxn], r[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	ll sum1 = 0, sum2 = 0;
	for(int i = 1 ; i <= n ; ++ i){
		sum1 += a[i] * a[i];
		sum2 += a[i];
		double tmp = sum2 * 1.0 / i;
		l[i] = sum1 * 1.0 / i - tmp * tmp;
	}
	sum1 = sum2 = 0;
	for(int i = n ; i >= 1 ; -- i){
		sum1 += a[i] * a[i];
		sum2 += a[i];
		double tmp = sum2 * 1.0 / (n - i + 1);
		r[i] = sum1 * 1.0 / (n - i + 1) - tmp * tmp;
	}
	double ans = 1e60;
	int pos = 0;
	for(int i = 1 ; i < n ; ++ i){
		if(l[i] + r[i+1] < ans)ans = l[i] + r[i+1], pos = i;
	}
	printf("%d\n", pos);
	return 0;
}

