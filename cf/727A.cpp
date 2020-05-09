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

int a, b;
int ans[maxn], cnt;

void solve(){
	ans[++cnt] = b;
	while(b != a){
		if(b < a){
			printf("NO\n");
			return;
		}
		if(b % 10 == 1)b /= 10;
		else if(b % 2 == 0)b /= 2;
		else{
			printf("NO\n");
			return;
		}
		ans[++cnt] = b;
	}
	printf("YES\n%d\n", cnt);
	for(int i = cnt ; i >= 1 ; -- i)printf("%d ", ans[i]);
	printf("\n");
}

int main(){
	scanf("%d%d", &a, &b);
	solve();
	return 0;
}

