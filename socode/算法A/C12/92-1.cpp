#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int cnt = 0;
		while(n){
			if(n&1)cnt++;
			n >>= 1;
		}
		if(cnt == 1)printf("1\n");
		else printf("0\n");
	}
	return 0;
}

