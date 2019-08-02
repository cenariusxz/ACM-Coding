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

ll C[55][55]; 

void init(){
	for(int i = 0 ; i <= 50 ; ++ i){
		for(int j = 0 ; j <= i ; ++ j){
			if(j == 0 || j == i)C[i][j] = 1;
			else C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
}

int main(){
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld\n",C[n][m]);
	return 0;
}

