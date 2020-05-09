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

int n;
int ans[10];

void solve(){
	int tmp = 1, res = 0;
	while(n){
		int num = n % 10;
		if(num > res)res = num;
		for(int i = 1 ; i <= num ; ++ i)ans[i] += tmp;
		n /= 10;
		tmp *= 10;
	}
	printf("%d\n", res);
	for(int i = 1 ; i <= res ; ++ i)printf("%d ", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}

