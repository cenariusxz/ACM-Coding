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

int n, d;
char s[maxn];

void solve(){
	int pos = 1;
	int step = 0;
	while(pos < n){
		int lst = 0;
		for(int i = pos + 1 ; i <= min(pos + d, n) ; ++ i){
			if(s[i] == '1')lst = i;
		}
		if(!lst){
			printf("-1\n");
			return;
		}
		pos = lst;
		step++;
	}
	printf("%d\n", step);
}

int main(){
	scanf("%d%d%s", &n, &d, s+1);
	solve();
	return 0;
}

