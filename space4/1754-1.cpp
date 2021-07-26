#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int n, a[maxn];
double p[maxn], p2[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	sort(a+1, a+1+n); 
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = i+1 ; j <= n ; ++ j){
			p[a[j] - a[i]] += 1.0 / (n*(n-1));
		}
	}
	for(int i = 1 ; i <= 4999 ; ++ i){
		for(int j = 1 ; i + j <= 4999 ; ++ j){
			p2[i+j] += p[i] * p[j];
		}
	}
	double ans = 0;
	for(int i = 1 ; i <= 4999 ; ++ i){
		for(int j = 0 ; j < i ; ++ j){
			ans += p[i] * p2[j];
		}
	}
	printf("%.12lf\n", ans * 8);
	return 0;
}

