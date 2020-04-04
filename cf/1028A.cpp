#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e2 + 5;
const int maxm = 1e6 + 5;

int n, m;
char s[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s", s[i] + 1);
	int rmin = INF, rmax = 0, cmin = INF, cmax = 0;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == 'B'){
				rmin = min(rmin, i);
				rmax = max(rmax, i);
				cmin = min(cmin, j);
				cmax = max(cmax, j);
			}
		}
	}
	printf("%d %d\n", (rmin + rmax)/2, (cmin + cmax)/2);
	return 0;
}

