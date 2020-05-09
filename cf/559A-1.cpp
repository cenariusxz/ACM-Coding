#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int a[10];

void solve(){
	int len = a[1] + a[2] + a[3];
	printf("%d\n", len*len - a[1]*a[1] - a[3]*a[3] - a[5]*a[5]);
}

int main(){
	for(int i = 1 ; i <= 6 ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

