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
		int m,L,R;
		scanf("%d%d%d",&m,&L,&R);
		printf("%d\n",R/m - (L-1)/m);
	}
	return 0;
}

