#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[105],cnt[105],n;

void solve(){
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	for(int i = 1 ; i <= n ; ++ i)cnt[a[i]] ^= 1;
	for(int i = 1 ; i <= 100 ; ++ i){
		if(cnt[i]){
			printf("1\n");
			return;
		}
	}
	printf("0\n");
}

int main(){
	while(scanf("%d", &n) && n)solve();
	return 0;
}

