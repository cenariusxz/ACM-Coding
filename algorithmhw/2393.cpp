#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e4 + 5;

int n,s,c[maxn],y[maxn];

int main(){
	scanf("%d%d",&n,&s);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&c[i],&y[i]);
	int Min = INF;
	ll ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		Min = min(Min+s, c[i]);
		ans += Min*(ll)y[i];
	}
	printf("%lld\n",ans);
	return 0;
}
