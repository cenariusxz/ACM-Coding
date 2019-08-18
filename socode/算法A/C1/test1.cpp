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

ll C(int i, int j){
	if(j == 0 || j == i)return 1;
	return C(i-1,j-1) + C(i-1,j);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld\n",C(n,m));
	return 0;
}

