#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int a[maxn];
int Max[maxn];

inline ll max(ll a, ll b){
	return a>b?a:b;	
}

int main(){
	int n;
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; ++i ){
		scanf("%d",&a[i]);	
	}
	Max[1] = a[1];
	for( int i = 2 ; i <= n ; ++ i ){
		Max[i]=max(Max[i-1], a[i]);	
	}
	int m;
	scanf("%d",&m);
	ll ans = 0;
	for( int i = 1 ; i <= m ; ++ i ){
		int h,w;
		scanf("%d%d",&w,&h);
		ans = max(ans, Max[w]) + h;
		printf("%I64d\n",ans - h);
	}
	return 0;
}

